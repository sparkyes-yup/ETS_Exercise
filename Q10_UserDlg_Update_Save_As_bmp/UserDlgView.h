
// UserDlgView.h : interface of the CUserDlgView class
//

#pragma once


class CUserDlgView : public CView
{
protected: // create from serialization only
	CUserDlgView() noexcept;
	DECLARE_DYNCREATE(CUserDlgView)

// Attributes
public:
	CUserDlgDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CUserDlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnToolsOptions();
private:
	enum DocumentType {None, Graphics};

	DocumentType m_documentType{ DocumentType::None };

	CString input_username;
	CString input_cpe_address;
	CString input_phone;
	CString input_fax;
	CString input_email;
	CString input_manu;
	CString input_model;
	CString input_serial;
	CString input_company;
	CString input_web;
	int input_f1{0};
	int input_f2{0};
	int input_f3{0};
	int input_f4{0};
	int input_f5{0};
};

#ifndef _DEBUG  // debug version in UserDlgView.cpp
inline CUserDlgDoc* CUserDlgView::GetDocument() const
   { return reinterpret_cast<CUserDlgDoc*>(m_pDocument); }
#endif

