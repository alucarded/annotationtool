#pragma once

#include "IAddObjectView.h"
#include "IAnnotationView.h"

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
	public ref class AddObjectForm : public System::Windows::Forms::Form, public IAddObjectView
	{
	public:
		AddObjectForm(IAnnotationView^ view) : m_annotation_view(view)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

        void AddObject(System::String^ name) override
        {
            m_annotation_view->AddObject(name);
        }

        virtual event SendObjectData^ ObjectAdded {
            void add(SendObjectData ^ d) {
                m_object_added_event += d;
            }
            void remove(SendObjectData ^ d) {
                m_object_added_event -= d;
            }
            void raise(System::String^ name, double aspect_ratio) {
                SendObjectData^ tmp = m_object_added_event;
                if (tmp) {
                    tmp->Invoke(name, aspect_ratio);
                }
            }
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
    private: System::Windows::Forms::CheckBox^  aspectRatioCheckBox;

    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::TextBox^  objectNameTextBox;

    private: System::Windows::Forms::RichTextBox^  richTextBox1;
    private: System::Windows::Forms::TextBox^  widthTextBox;
    private: System::Windows::Forms::TextBox^  heightTextBox;


    private: System::Windows::Forms::Button^  OKButton;
    private: System::Windows::Forms::Button^  cancelButton;
    protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

        SendObjectData^ m_object_added_event;
        IAnnotationView^ m_annotation_view;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->aspectRatioCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->objectNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->widthTextBox = (gcnew System::Windows::Forms::TextBox());
            this->heightTextBox = (gcnew System::Windows::Forms::TextBox());
            this->OKButton = (gcnew System::Windows::Forms::Button());
            this->cancelButton = (gcnew System::Windows::Forms::Button());
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
            // aspectRatioCheckBox
            // 
            this->aspectRatioCheckBox->AutoSize = true;
            this->aspectRatioCheckBox->Location = System::Drawing::Point(31, 135);
            this->aspectRatioCheckBox->Name = L"aspectRatioCheckBox";
            this->aspectRatioCheckBox->Size = System::Drawing::Size(115, 17);
            this->aspectRatioCheckBox->TabIndex = 2;
            this->aspectRatioCheckBox->Text = L"Fixed Aspect Ratio";
            this->aspectRatioCheckBox->UseVisualStyleBackColor = true;
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
            this->label4->Location = System::Drawing::Point(152, 155);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(38, 13);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Width:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(253, 155);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(41, 13);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Height:";
            // 
            // objectNameTextBox
            // 
            this->objectNameTextBox->Location = System::Drawing::Point(130, 20);
            this->objectNameTextBox->Name = L"objectNameTextBox";
            this->objectNameTextBox->Size = System::Drawing::Size(350, 20);
            this->objectNameTextBox->TabIndex = 6;
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(130, 52);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(350, 77);
            this->richTextBox1->TabIndex = 7;
            this->richTextBox1->Text = L"";
            // 
            // widthTextBox
            // 
            this->widthTextBox->Location = System::Drawing::Point(196, 152);
            this->widthTextBox->Name = L"widthTextBox";
            this->widthTextBox->Size = System::Drawing::Size(39, 20);
            this->widthTextBox->TabIndex = 8;
            // 
            // heightTextBox
            // 
            this->heightTextBox->Location = System::Drawing::Point(300, 152);
            this->heightTextBox->Name = L"heightTextBox";
            this->heightTextBox->Size = System::Drawing::Size(41, 20);
            this->heightTextBox->TabIndex = 9;
            // 
            // OKButton
            // 
            this->OKButton->Location = System::Drawing::Point(300, 181);
            this->OKButton->Name = L"OKButton";
            this->OKButton->Size = System::Drawing::Size(86, 23);
            this->OKButton->TabIndex = 10;
            this->OKButton->Text = L"OK";
            this->OKButton->UseVisualStyleBackColor = true;
            this->OKButton->Click += gcnew System::EventHandler(this, &AddObjectForm::OKButton_Click);
            // 
            // cancelButton
            // 
            this->cancelButton->Location = System::Drawing::Point(392, 181);
            this->cancelButton->Name = L"cancelButton";
            this->cancelButton->Size = System::Drawing::Size(86, 23);
            this->cancelButton->TabIndex = 11;
            this->cancelButton->Text = L"Cancel";
            this->cancelButton->UseVisualStyleBackColor = true;
            this->cancelButton->Click += gcnew System::EventHandler(this, &AddObjectForm::cancelButton_Click);
            // 
            // AddObjectForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(492, 216);
            this->Controls->Add(this->cancelButton);
            this->Controls->Add(this->OKButton);
            this->Controls->Add(this->heightTextBox);
            this->Controls->Add(this->widthTextBox);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->objectNameTextBox);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->aspectRatioCheckBox);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddObjectForm";
            this->Text = L"Add Object";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
        double aspect_ratio = 0.0;
        if (this->aspectRatioCheckBox->Checked) {
            // TODO: calculate aspect ratio
        }
        this->ObjectAdded(this->objectNameTextBox->Text, aspect_ratio);
        this->Close();
    }
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
    this->Close();
}
};
}
