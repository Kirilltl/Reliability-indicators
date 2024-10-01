#include "MyForm.h"
#define N 10000
#define T 15
#define step 0.1
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace InterfaceOfProgram; 
using namespace System::Windows::Forms::DataVisualization::Charting;

MyForm::MyForm()
{
    InitializeComponent();
}

MyForm::~MyForm()
{
    if (components)
    {
        delete components;
    }
}

std::vector<int> MyForm::parse_int(System::String^ input)
{
    std::vector<int> result;
    array<String^>^ split = input->Split(' ');
    for each (String ^ s in split)
    {
        result.push_back(Int32::Parse(s));
    }
    return result;
}

std::vector<double> MyForm::parse_double(System::String^ input)
{
    std::vector<double> result;
    array<String^>^ split = input->Split(' ');
    for each (String ^ s in split)
    {
        result.push_back(Double::Parse(s));
    }
    return result;
}

void MyForm::click_button(System::Object^ sender, System::EventArgs^ e)
{
    int numSB = Int32::Parse(textBox1->Text);
    std::vector<int> num_p_e = parse_int(textBox2->Text);
    int numC = Int32::Parse(textBox3->Text);
    std::vector<double> l = parse_double(textBox4->Text);
    std::vector<double> m = parse_double(textBox5->Text);
    rel_factor(numSB, num_p_e, numC, l, m);
    up_bound(numSB, num_p_e, l, m);
    low_bound_1(numSB, num_p_e, l, m);
    low_bound_2(numSB, num_p_e, l, m);
    display_chart();
    print_coefficient_min();
}

void MyForm::print_coefficient_min() {
    String^ filePath = "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\factor_time.txt";
    double min = Double::MaxValue;
    StreamReader^ sr = gcnew StreamReader(filePath);
    String^ line;
    while ((line = sr->ReadLine()) != nullptr) {
        array<String^>^ parts = line->Split(' ');
        if (parts->Length >= 2) {
            double val;
            if (Double::TryParse(parts[1], System::Globalization::NumberStyles::Any, System::Globalization::CultureInfo::InvariantCulture, val)) {
                if (val < min) {
                    min = val;
                }
            }
        }
    }
    sr->Close();
    if (min == Double::MaxValue) {
        min = 0;
    }
    textBox7->Text = min.ToString("F2", System::Globalization::CultureInfo::InvariantCulture);
}

void MyForm::read_data_for_graphic(Series^ series, String^ fileName) {
    StreamReader^ sr = gcnew StreamReader(fileName);
    String^ line;
    while ((line = sr->ReadLine()) != nullptr) {
        array<String^>^ split = line->Split(' ');
        double x = Convert::ToDouble(split[0], System::Globalization::CultureInfo::InvariantCulture);
        double y = Convert::ToDouble(split[1], System::Globalization::CultureInfo::InvariantCulture);
        series->Points->AddXY(x, y);
    }
    sr->Close();
}

void MyForm::display_chart() {
    chart1->Series->Clear(); 
    chart1->ChartAreas[0]->AxisY->Minimum = 0; //-0.1
    chart1->ChartAreas[0]->AxisY->Maximum = 1;
    array<String^>^ fileNames = gcnew array<String^> {
        "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\factor_time.txt",
        "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\up_bound.txt",
        "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\low_bound1.txt",
        "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\low_bound2.txt"
    };
    array<String^>^ seriesNames = gcnew array<String^> {
        "Коэффициент готовности от времени",
        "Верхняя граница", 
        "Нижняя граница, первый способ", 
        "Нижняя граница, второй способ"
    };
    array<Color>^ colors = gcnew array<Color> {
        Color::Olive,
        Color::Pink,
        Color::Orange,
        Color::Violet
    };
    for (int i = 0; i < fileNames->Length; ++i) {
        Series^ series = gcnew Series(seriesNames[i]);
        series->ChartType = SeriesChartType::Line;
        series->Color = colors[i];
        read_data_for_graphic(series, fileNames[i]);
        chart1->Series->Add(series);
    }
    chart1->Invalidate(); 
}

bool MyForm::is_any_system_operational(const std::vector<OldSystem>& systems)
{
    for (const auto& sys : systems) {
        if (sys.flag) return true;
    }
    return false;
}

void MyForm::rel_factor(int numSB, std::vector<int> num_p_e, int numC, std::vector<double> l, std::vector<double> m){
    int size = numSB;
    int sum = 0;
    int l_ctr = 0;
    int m_ctr = 0;
    for (int i = 0; i < size; ++i)
        sum += num_p_e[i];
    std::vector<int> time((int)(T / step));
    srand((unsigned int)std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        std::vector<OldSystem> Systems;
        std::vector<bool> Crews(numC);
        for (int block = 0; block < numSB; ++block) {
            for (int element = 0; element < num_p_e[block]; ++element) {
                Systems.push_back(OldSystem());
            }
        }
        for (int t = 0; t < time.size(); ++t) {
            for (int j = 0; j < sum; ++j) {
                if (Systems[j].flag || Systems[j].repair_crew != -1) {
                    Systems[j].time -= step;
                    if (Systems[j].time <= 0) {
                        Systems[j].flag = !Systems[j].flag;
                        if (Systems[j].flag) {
                            Systems[j].time = (-log((double)rand() / RAND_MAX)) / l[l_ctr];
                            l_ctr = (l_ctr + 1) % l.size();
                            Crews[Systems[j].repair_crew] = false;
                            Systems[j].repair_crew = -1;
                        }
                    }
                }
                bool flag2 = false;
                int idx;
                for (int k = 0; k < numC; ++k) {
                    if (!Crews[k]) {
                        flag2 = true;
                        idx = k;
                        break;
                    }
                }
                if (!Systems[j].flag && Systems[j].repair_crew == -1 && flag2) {
                    Systems[j].repair_crew = idx;
                    Crews[idx] = true;
                    Systems[j].time = (-log((double)rand() / RAND_MAX)) / m[m_ctr];
                    m_ctr = (m_ctr + 1) % m.size();
                }
            }
            int startIdx = 0;
            bool all_blocks_operational = true;
            for (int block = 0; block < numSB; ++block) {
                int endIdx = startIdx + num_p_e[block];
                std::vector<OldSystem> current_parallel_scheme(Systems.begin() + startIdx, Systems.begin() + endIdx);
                if (!is_any_system_operational(current_parallel_scheme)) {
                    all_blocks_operational = false;
                    break;
                }
                startIdx = endIdx;
            }
            if (all_blocks_operational) {
                time[t]++;
            }
            l_ctr = 0;
            m_ctr = 0;
        }
    }
    System::String^ filePath = "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\factor_time.txt";
    StreamWriter^ out = gcnew StreamWriter(filePath);
    int y = 0;
    for (double t = 0; t < T - 0.001; t += step)
    {
        String^ formattedString = String::Format(System::Globalization::CultureInfo::InvariantCulture, "{0:F1} {1}", t, (double)time[y] / N);
           
        out->WriteLine(formattedString);
        ++y;
    }
    out->Close();
    /*double averageMTBF = 0.0;
    double averageMTTR = 0.0;
    for (int i = 0; i < l.size(); ++i) {
        averageMTBF += 1.0 / l[i];
        averageMTTR += 1.0 / m[i];
    }
    averageMTBF /= l.size();
    averageMTTR /= m.size();

    double averageAvailability = averageMTBF / (averageMTBF + averageMTTR);
    String^ readinessFilePath = "C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\tmp.txt";
    StreamWriter^ readinessOut = gcnew StreamWriter(readinessFilePath);
    String^ formattedReadiness = String::Format(System::Globalization::CultureInfo::InvariantCulture, "{0:F4}", averageAvailability);
    readinessOut->WriteLine(formattedReadiness);
    readinessOut->Close();*/
}

void MyForm::up_bound(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m) {
    StreamWriter^ out = gcnew StreamWriter("C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\up_bound.txt");
    List<double>^ coefs = gcnew List<double>();
    double conv = 1.0;
    for (int block = 0; block < numSB; ++block) {
        double l1 = l[block];
        double m1 = m[block];
        double k11 = (m1 / (m1 + l1));

        if (num_p_e[block] == 1)
            coefs->Add(k11);
        else
            coefs->Add(1 - Math::Pow(1 - k11, num_p_e[block]));
    }

    for (int i = 0; i < coefs->Count; i++)
        conv *= coefs[i];

    for (double t = 0; t < T - 0.001; t += step) {
        String^ formattedString = String::Format(System::Globalization::CultureInfo::InvariantCulture, "{0:F1} {1}", t, conv);
        out->WriteLine(formattedString);
    }

    out->Close();
}

void MyForm::low_bound_1(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m) {
    StreamWriter^ out = gcnew StreamWriter("C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\low_bound1.txt");
    List<double>^ coefs = gcnew List<double>();
    double conv = 1.0;
    for (int block = 0; block < numSB; ++block) {
        double l1 = l[block]; 
        double m1 = m[block];
        double k11 = m1 / (m1 + l1);
        double k21 = (2 * m1 * l1 + Math::Pow(m1, 2)) / (2 * Math::Pow(l1, 2) + 2 * m1 * l1 + Math::Pow(m1, 2));
        if (num_p_e[block] == 1)
            coefs->Add(k11);
        else if (num_p_e[block] == 2)
            coefs->Add(k21);
        else
            coefs->Add(1 - (Math::Pow(1 - k11, num_p_e[block] - 2) * Math::Pow(1 - k21, 1)));
    }
    for (int i = 0; i < coefs->Count; i++)
        conv *= coefs[i];
    for (double t = 0; t < T - 0.001; t += step) {
        String^ formattedString = String::Format(System::Globalization::CultureInfo::InvariantCulture, "{0:F1} {1}", t, conv);
        out->WriteLine(formattedString);
    }
    out->Close();
}

void MyForm::low_bound_2(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m) {
    StreamWriter^ out = gcnew StreamWriter("C:\\Users\\79112\\source\\repos\\InterfaceOfProgram\\low_bound2.txt");
    List<double>^ coefs = gcnew List<double>();
    double conv = 1.0;
    for (int block = 0; block < numSB; ++block) {
        double l1 = l[block];
        double m1 = m[block];
        double k11 = (m1 / (m1 + l1));
        if (num_p_e[block] == 1 || num_p_e[block] == 2)
            coefs->Add(k11);
        else
            coefs->Add(1 - Math::Pow(1 - k11, num_p_e[block] - 1));
    }
    for (int i = 0; i < coefs->Count; i++)
        conv *= coefs[i];
    for (double t = 0; t < T - 0.001; t += step) {
        String^ formattedString = String::Format(System::Globalization::CultureInfo::InvariantCulture, "{0:F1} {1}", t, conv);
        out->WriteLine(formattedString);
    }
    out->Close();
}

int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
}
