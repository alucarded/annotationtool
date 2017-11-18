#pragma once

#include "IAnnotationView.h"
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

		NewProjectForm(IAnnotationView^ annotation_view) : m_annotation_view(annotation_view)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

        void UpdateProject(System::String^ name, System::String^ description, int mode) override
        {
            m_annotation_view->UpdateProject(name, description, mode);
        }

        // INewProjectView
        virtual event SendProjectDetails^ NewProjectCreated {
                void add(SendProjectDetails ^ d) {
                    project_created_event += d;
                }
                void remove(SendProjectDetails ^ d) {
                    project_created_event -= d;
                }
                void raise(System::String^ name, System::String^ description, int mode) {
                    SendProjectDetails^ tmp = project_created_event;
                    if (tmp) {
                        tmp->Invoke(name, description, mode);
                    }
                }
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
    private: System::Windows::Forms::Button^  cancelButton;
    protected:

    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::TextBox^  projectNameTextBox;
    private: System::Windows::Forms::RichTextBox^  descriptionTextBox;
    private: System::Windows::Forms::ComboBox^  modeComboBox;




	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

        SendProjectDetails^ project_created_event;
        IAnnotationView^ m_annotation_view;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
            this->OKButton = (gcnew System::Windows::Forms::Button());
            this->cancelButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->projectNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->descriptionTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->modeComboBox = (gcnew System::Windows::Forms::ComboBox());
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
            // cancelButton
            // 
            this->cancelButton->Location = System::Drawing::Point(341, 164);
            this->cancelButton->Name = L"cancelButton";
            this->cancelButton->Size = System::Drawing::Size(75, 23);
            this->cancelButton->TabIndex = 1;
            this->cancelButton->Text = L"Cancel";
            this->cancelButton->UseVisualStyleBackColor = true;
            this->cancelButton->Click += gcnew System::EventHandler(this, &NewProjectForm::cancelButton_Click);
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
            // projectNameTextBox
            // 
            this->projectNameTextBox->Location = System::Drawing::Point(96, 24);
            this->projectNameTextBox->Name = L"projectNameTextBox";
            this->projectNameTextBox->Size = System::Drawing::Size(209, 20);
            this->projectNameTextBox->TabIndex = 5;
            // 
            // descriptionTextBox
            // 
            this->descriptionTextBox->Location = System::Drawing::Point(96, 56);
            this->descriptionTextBox->Name = L"descriptionTextBox";
            this->descriptionTextBox->Size = System::Drawing::Size(309, 71);
            this->descriptionTextBox->TabIndex = 6;
            this->descriptionTextBox->Text = L"";
            // 
            // modeComboBox
            // 
            this->modeComboBox->FormattingEnabled = true;
            this->modeComboBox->Location = System::Drawing::Point(96, 132);
            this->modeComboBox->Name = L"modeComboBox";
            this->modeComboBox->Size = System::Drawing::Size(121, 21);
            this->modeComboBox->TabIndex = 7;
            // 
            // NewProjectForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(430, 199);
            this->Controls->Add(this->modeComboBox);
            this->Controls->Add(this->descriptionTextBox);
            this->Controls->Add(this->projectNameTextBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->cancelButton);
            this->Controls->Add(this->OKButton);
            this->Name = L"NewProjectForm";
            this->Text = L"New Project";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
        this->NewProjectCreated(projectNameTextBox->Text, descriptionTextBox->Text, modeComboBox->SelectedIndex);
        this->Close();
	}
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
    this->Close();
}
};
}
