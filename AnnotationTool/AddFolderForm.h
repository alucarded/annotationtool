#pragma once

#include "IAnnotationView.h"
#include "IAddFolderView.h"

namespace AnnotationTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddFolderForm
	/// </summary>
	public ref class AddFolderForm : public System::Windows::Forms::Form, public IAddFolderView
	{
	public:
		AddFolderForm(IAnnotationView^ parent_view) : m_annotation_view(parent_view)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

        void AddPaths(System::String^ root_path, System::Collections::ArrayList^ image_names, bool is_recursive) override
        {
            m_annotation_view->AddPaths(root_path, image_names, is_recursive);
        }

        // INewProjectView
        virtual event SendPathData^ NewFolderAdded {
            void add(SendPathData ^ d) {
                new_folder_added += d;
            }
            void remove(SendPathData ^ d) {
                new_folder_added -= d;
            }
            void raise(System::String^ root_path, bool is_recursive) {
                SendPathData^ tmp = new_folder_added;
                if (tmp) {
                    tmp->Invoke(root_path, is_recursive);
                }
            }
        }

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AddFolderForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
    protected:
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::TextBox^  folderPathTextBox;
    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button3;
    private: System::Windows::Forms::CheckBox^  checkBox1;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

        IAnnotationView^ m_annotation_view;
        SendPathData^ new_folder_added;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
            this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->folderPathTextBox = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Image Folder:";
            // 
            // folderPathTextBox
            // 
            this->folderPathTextBox->Location = System::Drawing::Point(89, 37);
            this->folderPathTextBox->Name = L"folderPathTextBox";
            this->folderPathTextBox->Size = System::Drawing::Size(218, 20);
            this->folderPathTextBox->TabIndex = 1;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(250, 97);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 2;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &AddFolderForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(331, 97);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 3;
            this->button2->Text = L"Cancel";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &AddFolderForm::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(313, 35);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(75, 23);
            this->button3->TabIndex = 4;
            this->button3->Text = L"Browse...";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &AddFolderForm::button3_Click);
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Location = System::Drawing::Point(89, 63);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(143, 17);
            this->checkBox1->TabIndex = 5;
            this->checkBox1->Text = L"Recursive Image Search";
            this->checkBox1->UseVisualStyleBackColor = true;
            // 
            // AddFolderForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(418, 132);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->folderPathTextBox);
            this->Controls->Add(this->label1);
            this->Name = L"AddFolderForm";
            this->Text = L"Add Folder";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
        this->NewFolderAdded(this->folderPathTextBox->Text, this->checkBox1->Checked);
        this->Close();
    }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
    System::Windows::Forms::DialogResult result = this->folderBrowserDialog1->ShowDialog();
    if (result == System::Windows::Forms::DialogResult::OK) {
        this->folderPathTextBox->Text = folderBrowserDialog1->SelectedPath;
    }
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
    this->Close();
}
};
}
