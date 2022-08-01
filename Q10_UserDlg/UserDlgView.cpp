
// UserDlgView.cpp : implementation of the CUserDlgView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "UserDlg.h"
#endif

#include "UserDlgDoc.h"
#include "UserDlgView.h"
#include "CUserInfos.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserDlgView

IMPLEMENT_DYNCREATE(CUserDlgView, CView)

BEGIN_MESSAGE_MAP(CUserDlgView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOLS_OPTIONS, &CUserDlgView::OnToolsOptions)
END_MESSAGE_MAP()

// CUserDlgView construction/destruction

CUserDlgView::CUserDlgView() noexcept
{
	// TODO: add construction code here

}

CUserDlgView::~CUserDlgView()
{
}

BOOL CUserDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUserDlgView drawing

void CUserDlgView::OnDraw(CDC* pDC)
{
	CUserDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CString i1;
	i1.Format(L"%d", input_f1);
	CString i2;
	i2.Format(L"%d", input_f2);
	CString i3;
	i3.Format(L"%d", input_f3);
	CString i4;
	i4.Format(L"%d", input_f4);
	CString i5;
	i5.Format(L"%d", input_f5);

	pDC->TextOutW(200, 100, _T("Username:"));
	pDC->TextOutW(350, 100, input_username);
	pDC->TextOutW(200, 200, _T("Complete address:"));
	pDC->TextOutW(350, 200, input_cpe_address);
	pDC->TextOutW(200, 300, _T("Phone number:"));
	pDC->TextOutW(350, 300, input_phone);
	pDC->TextOutW(200, 400, _T("Fax number:"));
	pDC->TextOutW(350, 400, input_fax);
	pDC->TextOutW(200, 500, _T("Email address:"));
	pDC->TextOutW(350, 500, input_email);
	pDC->TextOutW(200, 600, _T("Manufacturer:"));
	pDC->TextOutW(350, 600, input_manu);
	pDC->TextOutW(200, 700, _T("Model:"));
	pDC->TextOutW(350, 700, input_model);
	pDC->TextOutW(200, 800, _T("Serial number:"));
	pDC->TextOutW(350, 800, input_serial);
	pDC->TextOutW(200, 900, _T("Company name:"));
	pDC->TextOutW(350, 900, input_company);
	pDC->TextOutW(200, 1000, _T("Web address: "));
	pDC->TextOutW(350, 1000, input_web);

	pDC->TextOutW(600, 100, _T("Field 1:"));
	pDC->TextOutW(750, 100, i1);
	pDC->TextOutW(600, 200, _T("Field 2:"));
	pDC->TextOutW(750, 200, i2);
	pDC->TextOutW(600, 300, _T("Field 3:"));
	pDC->TextOutW(750, 300, i3);
	pDC->TextOutW(600, 400, _T("Field 4:"));
	pDC->TextOutW(750, 400, i4);
	pDC->TextOutW(600, 500, _T("Field 5:"));
	pDC->TextOutW(750, 500, i5);


}

void CUserDlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUserDlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CUserDlgView diagnostics

#ifdef _DEBUG
void CUserDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CUserDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserDlgDoc* CUserDlgView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserDlgDoc)));
	return (CUserDlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserDlgView message handlers


void CUserDlgView::OnToolsOptions()
{
	// TODO: Add your command handler code here
	CUserInfos dlgUserInfos;
	// will launch a dialog
	dlgUserInfos.input_username = input_username;
	dlgUserInfos.input_cpe_address = input_cpe_address;
	dlgUserInfos.input_phone = input_phone;
	dlgUserInfos.input_fax = input_fax;
	dlgUserInfos.input_email = input_email;
	dlgUserInfos.input_manu = input_manu;
	dlgUserInfos.input_model = input_model;
	dlgUserInfos.input_serial = input_serial;
	dlgUserInfos.input_company = input_company;
	dlgUserInfos.input_web = input_web;
	dlgUserInfos.input_f1 = input_f1;
	dlgUserInfos.input_f2 = input_f2;
	dlgUserInfos.input_f3 = input_f3;
	dlgUserInfos.input_f4 = input_f4;
	dlgUserInfos.input_f5 = input_f5;

	if (dlgUserInfos.DoModal() == IDOK) {
		input_username = dlgUserInfos.input_username;
		input_cpe_address = dlgUserInfos.input_cpe_address;
		input_phone = dlgUserInfos.input_phone;
		input_fax = dlgUserInfos.input_fax;
		input_email = dlgUserInfos.input_email;
		input_manu = dlgUserInfos.input_manu;
		input_model = dlgUserInfos.input_model;
		input_serial = dlgUserInfos.input_serial;
		input_company = dlgUserInfos.input_company;
		input_web = dlgUserInfos.input_web;
		input_f1 = dlgUserInfos.input_f1;
		input_f2 = dlgUserInfos.input_f2;
		input_f3 = dlgUserInfos.input_f3;
		input_f4 = dlgUserInfos.input_f4;
		input_f5 = dlgUserInfos.input_f5;
	}
	Invalidate();
	UpdateWindow();
}

