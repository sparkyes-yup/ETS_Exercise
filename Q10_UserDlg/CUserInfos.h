#pragma once


// CUserInfos dialog

class CUserInfos : public CDialog
{
	DECLARE_DYNAMIC(CUserInfos)

public:
	CUserInfos(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserInfos();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USERINFOS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
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
	int input_f1;
	int input_f2;
	int input_f3;
	int input_f4;
	int input_f5;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
