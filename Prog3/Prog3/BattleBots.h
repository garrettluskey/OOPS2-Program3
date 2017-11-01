#pragma once
#include "FighterBot.h"
#include "HidingBot.h"
#include "RandomBot.h"
#include "VBot.h"
#include "LList.h"
namespace Lab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		FighterBot *F;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::NumericUpDown^  nudX;
	private: System::Windows::Forms::NumericUpDown^  nudY;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;




			 LList *BotList;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnAddBot;
	protected:


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnAddBot = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->nudX = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudY))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(12, 135);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(646, 292);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// btnAddBot
			// 
			this->btnAddBot->Location = System::Drawing::Point(583, 12);
			this->btnAddBot->Name = L"btnAddBot";
			this->btnAddBot->Size = System::Drawing::Size(75, 23);
			this->btnAddBot->TabIndex = 1;
			this->btnAddBot->Text = L"Add Bot";
			this->btnAddBot->UseVisualStyleBackColor = true;
			this->btnAddBot->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(554, 70);
			this->trackBar1->Maximum = 500;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 3;
			this->trackBar1->TickFrequency = 100;
			this->trackBar1->Value = 100;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Fighter Bot", L"Hiding Bot", L"Random Bot" });
			this->comboBox1->Location = System::Drawing::Point(12, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Fighter Bot";
			// 
			// nudX
			// 
			this->nudX->Location = System::Drawing::Point(197, 15);
			this->nudX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudX->Name = L"nudX";
			this->nudX->Size = System::Drawing::Size(120, 20);
			this->nudX->TabIndex = 7;
			// 
			// nudY
			// 
			this->nudY->Location = System::Drawing::Point(379, 15);
			this->nudY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudY->Name = L"nudY";
			this->nudY->Size = System::Drawing::Size(120, 20);
			this->nudY->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(135, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Select Bot";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(505, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Spawn Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(323, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Spawn X";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 439);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nudY);
			this->Controls->Add(this->nudX);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->btnAddBot);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudY))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->SelectedItem == "Fighter Bot") {
			BotList->Insert(new FighterBot((int)nudX->Value, (int)nudY->Value, this->panel1));
		}
		else if (comboBox1->SelectedItem == "Hiding Bot") {
			BotList->Insert(new HidingBot((int)nudX->Value, (int)nudY->Value, this->panel1));
		}
		else if (comboBox1->SelectedItem == "Random Bot") {
			BotList->Insert(new RandomBot((int)nudX->Value, (int)nudY->Value, this->panel1));
		}
		
		
		panel1->Invalidate();
		//this->panel1->Invalidate();
		//BotList.Insert(dynamic_cast<VBot*>(F));
		
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		F->Move();
		panel1->Invalidate();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		BotList = new LList;
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		BotList->ShowAll();
		
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	BotList->MoveAll();
	BotList->BattleManager();
	BotList->DeleteDead();
	panel1->Invalidate();
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	timer1->Interval = trackBar1->Value;
}
private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	timer1->Enabled = false;

	delete BotList;
}
};
}
