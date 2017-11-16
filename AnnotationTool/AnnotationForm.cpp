#include "AnnotationForm.h"
#include "AnnotationPresenter.h"

#include "AnnotationModel.h" // unmanaged

#pragma managed

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
    AnnotationModel* model = new AnnotationModel();
	AnnotationTool::AnnotationForm form(model);
    AnnotationPresenter presenter(%form, model);
	Application::Run(%form);
}

