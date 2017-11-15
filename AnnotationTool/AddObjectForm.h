#pragma once

namespace AnnotationTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddObjectForm
	/// </summary>
	public ref class AddObjectForm : public System::Windows::Forms::Form
	{
	public:
		AddObjectForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AddObjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::CheckBox^  checkBox1;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::RichTextBox^  richTextBox1;
    private: System::Windows::Forms::TextBox^  textBox2;
    private: System::Windows::Forms::TextBox^  textBox3;
    protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(28, 23);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(72, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Object Name:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(28, 55);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(63, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Description:";
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Location = System::Drawing::Point(31, 135);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(115, 17);
            this->checkBox1->TabIndex = 2;
            this->checkBox1->Text = L"Fixed Aspect Ratio";
            this->checkBox1->UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(75, 155);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(71, 13);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Aspect Ratio:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(170, 155);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(38, 13);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Width:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(295, 155);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(41, 13);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Height:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(130, 20);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(350, 20);
            this->textBox1->TabIndex = 6;
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(130, 52);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(350, 77);
            this->richTextBox1->TabIndex = 7;
            this->richTextBox1->Text = L"";
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(214, 152);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(39, 20);
            this->textBox2->TabIndex = 8;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(353, 152);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(41, 20);
            this->textBox3->TabIndex = 9;
            // 
            // AddObjectForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(492, 216);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddObjectForm";
            this->Text = L"AddObjectForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	};
}
