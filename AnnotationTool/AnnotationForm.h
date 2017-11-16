#pragma once

#include "IAnnotationView.h"
#include "NewProjectForm.h"
#include "NewProjectPresenter.h"

#include "AnnotationModel.h" // unmanaged

#pragma managed

namespace AnnotationTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AnnotationForm
	/// </summary>
	public ref class AnnotationForm : public System::Windows::Forms::Form, public IAnnotationView
	{
	public:
		AnnotationForm(AnnotationModel * model) : m_model(model)
		{
			InitializeComponent();

            // Add tree nodes
            objectsNode = (gcnew System::Windows::Forms::TreeNode(L"Objects"));
            foldersNode = (gcnew System::Windows::Forms::TreeNode(L"Folders"));
            projectNode = (gcnew System::Windows::Forms::TreeNode(L"Project", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
                objectsNode,
                    foldersNode
            }));
            objectsNode->ContextMenuStrip = this->ctxMenuObject;
            objectsNode->Name = L"ObjectsNode";
            objectsNode->Text = L"Objects";
            foldersNode->ContextMenuStrip = this->ctxMenuFolder;
            foldersNode->Name = L"FoldersNode";
            foldersNode->Text = L"Folders";
            projectNode->BackColor = System::Drawing::Color::Transparent;
            projectNode->ForeColor = System::Drawing::Color::Black;
            projectNode->Name = L"ProjectNode";
            projectNode->Text = L"Project";
            this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { projectNode });
		}

        // IAnnotationView
        void UpdateProject() override {
            
        }

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AnnotationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
    private: System::Windows::Forms::ContextMenuStrip^  ctxMenuObject;
    private: System::Windows::Forms::ToolStripMenuItem^  addObjectToolStripMenuItem;
    private: System::Windows::Forms::ContextMenuStrip^  ctxMenuFolder;
    private: System::Windows::Forms::ToolStripMenuItem^  addFolderToolStripMenuItem;
    private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
        System::Windows::Forms::TreeNode^  objectsNode;
        System::Windows::Forms::TreeNode^  foldersNode;
        System::Windows::Forms::TreeNode^  projectNode;

        AnnotationModel * m_model;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            this->ctxMenuObject = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->addObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->ctxMenuFolder = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->addFolderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->treeView1 = (gcnew System::Windows::Forms::TreeView());
            this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
            this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
            this->ctxMenuObject->SuspendLayout();
            this->ctxMenuFolder->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            // 
            // ctxMenuObject
            // 
            this->ctxMenuObject->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addObjectToolStripMenuItem });
            this->ctxMenuObject->Name = L"ctxMenuObject";
            this->ctxMenuObject->Size = System::Drawing::Size(135, 26);
            // 
            // addObjectToolStripMenuItem
            // 
            this->addObjectToolStripMenuItem->Name = L"addObjectToolStripMenuItem";
            this->addObjectToolStripMenuItem->Size = System::Drawing::Size(134, 22);
            this->addObjectToolStripMenuItem->Text = L"Add Object";
            this->addObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &AnnotationForm::addObjectToolStripMenuItem_Click);
            // 
            // ctxMenuFolder
            // 
            this->ctxMenuFolder->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addFolderToolStripMenuItem });
            this->ctxMenuFolder->Name = L"ctxMenuFolder";
            this->ctxMenuFolder->Size = System::Drawing::Size(133, 26);
            // 
            // addFolderToolStripMenuItem
            // 
            this->addFolderToolStripMenuItem->Name = L"addFolderToolStripMenuItem";
            this->addFolderToolStripMenuItem->Size = System::Drawing::Size(132, 22);
            this->addFolderToolStripMenuItem->Text = L"Add Folder";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(204, 34);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(613, 498);
            this->pictureBox1->TabIndex = 1;
            this->pictureBox1->TabStop = false;
            // 
            // menuStrip1
            // 
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                this->fileToolStripMenuItem,
                    this->editToolStripMenuItem, this->helpToolStripMenuItem
            });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(829, 24);
            this->menuStrip1->TabIndex = 2;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
                this->newToolStripMenuItem,
                    this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->exportToolStripMenuItem, this->exitToolStripMenuItem
            });
            this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
            this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
            this->fileToolStripMenuItem->Text = L"File";
            // 
            // newToolStripMenuItem
            // 
            this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
            this->newToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->newToolStripMenuItem->Text = L"New";
            this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &AnnotationForm::newToolStripMenuItem_Click);
            // 
            // openToolStripMenuItem
            // 
            this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
            this->openToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->openToolStripMenuItem->Text = L"Open..";
            // 
            // saveToolStripMenuItem
            // 
            this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
            this->saveToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->saveToolStripMenuItem->Text = L"Save";
            // 
            // saveAsToolStripMenuItem
            // 
            this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
            this->saveAsToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->saveAsToolStripMenuItem->Text = L"Save As...";
            // 
            // exportToolStripMenuItem
            // 
            this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
            this->exportToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->exportToolStripMenuItem->Text = L"Export...";
            // 
            // exitToolStripMenuItem
            // 
            this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
            this->exitToolStripMenuItem->Size = System::Drawing::Size(123, 22);
            this->exitToolStripMenuItem->Text = L"Exit";
            // 
            // editToolStripMenuItem
            // 
            this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
            this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
            this->editToolStripMenuItem->Text = L"Edit";
            // 
            // helpToolStripMenuItem
            // 
            this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
            this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
            this->helpToolStripMenuItem->Text = L"Help";
            // 
            // treeView1
            // 
            this->treeView1->Location = System::Drawing::Point(12, 34);
            this->treeView1->Name = L"treeView1";
            this->treeView1->Size = System::Drawing::Size(186, 498);
            this->treeView1->TabIndex = 3;
            this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &AnnotationForm::treeView1_AfterSelect);
            // 
            // notifyIcon1
            // 
            this->notifyIcon1->Text = L"notifyIcon1";
            this->notifyIcon1->Visible = true;
            // 
            // AnnotationForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(829, 565);
            this->Controls->Add(this->treeView1);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->menuStrip1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"AnnotationForm";
            this->Text = L"AnnotationForm";
            this->ctxMenuObject->ResumeLayout(false);
            this->ctxMenuFolder->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
	}
private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	NewProjectForm^ new_form = gcnew NewProjectForm();
    NewProjectPresenter^ new_presenter = gcnew NewProjectPresenter(new_form, m_model);
	new_form->ShowDialog();
}
private: System::Void addObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    // TODO: add object: update both View (here) and Model part
    objectsNode->Nodes->Add(gcnew TreeNode(L"Object"));
}

};
}
