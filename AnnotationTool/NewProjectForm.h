#pragma once

#include "INewProjectView.h"

namespace AnnotationTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o NewProjectForm
	/// </summary>
	public ref class NewProjectForm : public System::Windows::Forms::Form, public INewProjectView
	{
	public:
		NewProjectForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

        void UpdateProject() override
        {

        }

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~NewProjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OKButton;
	protected:
	private: System::Windows::Forms::Button^  CancelButton;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::RichTextBox^  richTextBox1;
    private: System::Windows::Forms::ComboBox^  comboBox1;

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
            this->OKButton = (gcnew System::Windows::Forms::Button());
            this->CancelButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // OKButton
            // 
            this->OKButton->Location = System::Drawing::Point(241, 164);
            this->OKButton->Name = L"OKButton";
            this->OKButton->Size = System::Drawing::Size(75, 23);
            this->OKButton->TabIndex = 0;
            this->OKButton->Text = L"OK";
            this->OKButton->UseVisualStyleBackColor = true;
            this->OKButton->Click += gcnew System::EventHandler(this, &NewProjectForm::OKButton_Click);
            // 
            // CancelButton
            // 
            this->CancelButton->Location = System::Drawing::Point(341, 164);
            this->CancelButton->Name = L"CancelButton";
            this->CancelButton->Size = System::Drawing::Size(75, 23);
            this->CancelButton->TabIndex = 1;
            this->CancelButton->Text = L"Cancel";
            this->CancelButton->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(16, 27);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(74, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Project Name:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(16, 56);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(63, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Description:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(16, 132);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(37, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Mode:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(96, 24);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(209, 20);
            this->textBox1->TabIndex = 5;
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(96, 56);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(309, 71);
            this->richTextBox1->TabIndex = 6;
            this->richTextBox1->Text = L"";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(96, 132);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 21);
            this->comboBox1->TabIndex = 7;
            // 
            // NewProjectForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(430, 199);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->CancelButton);
            this->Controls->Add(this->OKButton);
            this->Name = L"NewProjectForm";
            this->Text = L"New Project";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
        this->Close();
	}
	};
}
