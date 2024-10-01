#pragma once
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms::DataVisualization::Charting;

namespace InterfaceOfProgram {
	struct OldSystem
	{
		bool flag;
		double time;
		int repair_crew;
		OldSystem() : flag(false), time(0), repair_crew(0) {}
	};
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm();

	protected:
		~MyForm();
		void display_chart();
		void read_data_for_graphic(Series^ series, String^ fileName);
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	protected:
	private:
		System::ComponentModel::Container ^components;
		void click_button(System::Object^ sender, System::EventArgs^ e);
		void up_bound(int numSB, std::vector<int> num_p_e,std::vector<double> l, std::vector<double> m);
		void low_bound_1(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m);
		void low_bound_2(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m);
		//void print_factor_bound(int numSB, std::vector<int> num_p_e, std::vector<double> l, std::vector<double> m);
		std::vector<int> parse_int(System::String^ input);
		std::vector<double> parse_double(System::String^ input);
		//void print_coefficient_sr();
		void print_coefficient_min();
		void rel_factor(int numSB, std::vector<int> num_p_e, int num_c, std::vector<double> l, std::vector<double> m);
		bool is_any_system_operational(const std::vector<OldSystem>& systems);
		
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(201, 7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Расчет";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::click_button);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(348, 20);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(143, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(348, 68);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(143, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(348, 115);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(143, 22);
			this->textBox3->TabIndex = 4;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->label2->Location = System::Drawing::Point(10, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(262, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Количество последовательных блоков";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(257, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Количество параллельных элементов";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Количество ремонтных бригад";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(499, 258);
			this->panel1->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(348, 210);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(143, 22);
			this->textBox5->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 210);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(220, 16);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Интенсивности восстановления";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(348, 165);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(143, 22);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(158, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Интенсивности отказа";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Khaki;
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(2, 252);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(499, 47);
			this->panel2->TabIndex = 10;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(18, 14);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(355, 16);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Коэффициент готовности в установившемся режиме";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Tan;
			this->panel6->Controls->Add(this->textBox7);
			this->panel6->Controls->Add(this->label9);
			this->panel6->Location = System::Drawing::Point(499, 252);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(689, 47);
			this->panel6->TabIndex = 15;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(388, 11);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(49, 22);
			this->textBox7->TabIndex = 13;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Bisque;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(499, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(689, 250);
			this->chart1->TabIndex = 11;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Bisque;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->label5->Location = System::Drawing::Point(838, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 22);
			this->label5->TabIndex = 12;
			this->label5->Text = L"t";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Bisque;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(501, 2);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 22);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Kг(t)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 299);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
