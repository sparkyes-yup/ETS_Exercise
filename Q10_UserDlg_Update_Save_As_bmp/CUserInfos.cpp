// CUserInfos.cpp : implementation file
//

#include "pch.h"
#include "UserDlg.h"
#include "CUserInfos.h"
#include "afxdialogex.h"
#include "winuser.h"
#include <fstream>
#include <windows.h>
#include <gdiplus.h>
#include <iostream>

using namespace Gdiplus;

// CUserInfos dialog

IMPLEMENT_DYNAMIC(CUserInfos, CDialog)

CUserInfos::CUserInfos(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_USERINFOS, pParent)
	, input_username(_T(""))
	, input_cpe_address(_T(""))
	, input_phone(_T(""))
	, input_fax(_T(""))
	, input_email(_T(""))
	, input_manu(_T(""))
	, input_model(_T(""))
	, input_serial(_T(""))
	, input_company(_T(""))
	, input_web(_T(""))
	, input_f1(0)
	, input_f2(0)
	, input_f3(0)
	, input_f4(0)
	, input_f5(0)
{

}

CUserInfos::~CUserInfos()
{
}

void CUserInfos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, input_username);
	DDX_Text(pDX, IDC_EDIT2, input_cpe_address);
	DDX_Text(pDX, IDC_EDIT3, input_phone);
	DDX_Text(pDX, IDC_EDIT4, input_fax);
	DDX_Text(pDX, IDC_EDIT5, input_email);
	DDX_Text(pDX, IDC_EDIT6, input_manu);
	DDX_Text(pDX, IDC_EDIT7, input_model);
	DDX_Text(pDX, IDC_EDIT8, input_serial);
	DDX_Text(pDX, IDC_EDIT9, input_company);
	DDX_Text(pDX, IDC_EDIT10, input_web);
	DDX_Text(pDX, IDC_EDIT11, input_f1);
	DDX_Text(pDX, IDC_EDIT12, input_f2);
	DDX_Text(pDX, IDC_EDIT13, input_f3);
	DDX_Text(pDX, IDC_EDIT14, input_f4);
	DDX_Text(pDX, IDC_EDIT15, input_f5);
}


BEGIN_MESSAGE_MAP(CUserInfos, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &CUserInfos::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserInfos::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserInfos message handlers

/*
void CUserInfos::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	LPCTSTR pszFilter = _T("Graphics ((.bmp)|*.bmp||");

	CFileDialog dlgFile(FALSE, _T("bmp"), _T("Untitled.bmp"), OFN_OVERWRITEPROMPT, pszFilter, AfxGetMainWnd());

	if (IDOK == dlgFile.DoModal()) {
		try
		{
			CStdioFile file(dlgFile.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeText);

			if (dlgFile.GetFileExt() == _T("bmp")) {
				UpdateData();
				CString coordinate;
				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 100);
				file.WriteString(coordinate);
				file.WriteString( _T("Username:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 100);
				file.WriteString(coordinate);
				file.WriteString(input_username);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				file.WriteString(_T("Complete address:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				file.WriteString(input_cpe_address);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 300);
				file.WriteString(coordinate);
				file.WriteString(_T("Phone number:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 300);
				file.WriteString(coordinate);
				file.WriteString(input_phone);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 400);
				file.WriteString(coordinate);
				file.WriteString(_T("Fax number:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 400);
				file.WriteString(coordinate);
				file.WriteString(input_fax);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 500);
				file.WriteString(coordinate);
				file.WriteString(_T("Email address:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 500);
				file.WriteString(coordinate);
				file.WriteString(input_email);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				file.WriteString(_T("Manufacturer:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				file.WriteString(input_manu);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 700);
				file.WriteString(coordinate);
				file.WriteString(_T("Model:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 700);
				file.WriteString(coordinate);
				file.WriteString(input_model);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 800);
				file.WriteString(coordinate);
				file.WriteString(_T("Serial number:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 800);
				file.WriteString(coordinate);
				file.WriteString(input_serial);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 900);
				file.WriteString(coordinate);
				file.WriteString(_T("Company name:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 900);
				file.WriteString(coordinate);
				file.WriteString(input_company);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 1000);
				file.WriteString(coordinate);
				file.WriteString(_T("Web address:\n"));
				coordinate.Format(_T("%d\n"), 350);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 1000);
				file.WriteString(coordinate);
				file.WriteString(input_web);
				file.WriteString(_T("\n"));

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

				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 100);
				file.WriteString(coordinate);
				file.WriteString(_T("Field 1:\n"));
				coordinate.Format(_T("%d\n"), 750);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 100);
				file.WriteString(coordinate);
				file.WriteString(i1);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				file.WriteString(_T("Field 2:\n"));
				coordinate.Format(_T("%d\n"), 750);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 200);
				file.WriteString(coordinate);
				file.WriteString(i2);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 300);
				file.WriteString(coordinate);
				file.WriteString(_T("Field 3:\n"));
				coordinate.Format(_T("%d\n"), 750);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 300);
				file.WriteString(coordinate);
				file.WriteString(i3);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 400);
				file.WriteString(coordinate);
				file.WriteString(_T("Field 4:\n"));
				coordinate.Format(_T("%d\n"), 750);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 400);
				file.WriteString(coordinate);
				file.WriteString(i4);
				file.WriteString(_T("\n"));

				coordinate.Format(_T("%d\n"), 600);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 500);
				file.WriteString(coordinate);
				file.WriteString(_T("Field 5:\n"));
				coordinate.Format(_T("%d\n"), 750);
				file.WriteString(coordinate);
				coordinate.Format(_T("%d\n"), 500);
				file.WriteString(coordinate);
				file.WriteString(i5);


			}
		}
		catch (CFileException* pe) {
			CString error;
			error.Format(_T("File could not be saved, cause = %d\n"), pe->m_cause);
			AfxMessageBox(error);
			pe->Delete();
		}
	}
}
*/

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}
	free(pImageCodecInfo);
	return -1;  // Failure
}

void CUserInfos::OnBnClickedButton2()
{

//	TRACE("This is a TRACE statement from OnBnClickedButton2() \n");

	// Retrieves the specified system metric or system configuration setting.
	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);	// The width of the screen of the primary display monitor in pixels.
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);	// The height of the screen of the primary display monitor in pixels.

	// Retrieves a handle to the desktop window
	HWND hDesktopWnd = ::GetDesktopWindow();
	// Get the device context(DC) of the desktop window 
	HDC hDesktopDC = ::GetDC(hDesktopWnd);
	// Create a compatible DC for the Desktop DC
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	// Create a compatible bitmap to select into that compatible DC
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC,
		nScreenWidth, nScreenHeight);
	// Selecting the bitmap into the compatible DC
	SelectObject(hCaptureDC, hCaptureBitmap);

	// TODO: Add your control notification handler code here
	LPCTSTR pszFilter = _T("Graphics ((.bmp)|*.bmp||");

	CFileDialog dlgFile(FALSE, _T("bmp"), _T("Untitled.bmp"), OFN_OVERWRITEPROMPT, pszFilter, AfxGetMainWnd());
	/*
	
	*/
	if (IDOK == dlgFile.DoModal()) {
		try
		{
			// transfer of the color data corresponding to a rectangle of pixels from the specified source DC into a destination DC
			BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight,
				hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);


			//SaveCapturedBitmap(hCaptureBitmap); //Place holder - Put your code
			//here to save the captured image to disk

			// Convert HBitmap to Bitmap;
			GdiplusStartupInput gdiplusStartupInput;
			ULONG_PTR gdiplusToken;
			//TRACE("The status of GdiplusStartup is %d\n", GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL));	//return 0; which means ok (function succeeds)
			GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

			Bitmap* image = new Bitmap(hCaptureBitmap, NULL);

			CLSID myClsId;

			
			if (dlgFile.GetFileExt() == _T("bmp")) {

				int retVal = GetEncoderClsid(L"image/bmp", &myClsId);
				//TRACE("The class identifier (CLSID) of the encoder is %d\n", retVal);	// return 0; should be successful.

				//image->Save(L"E:\\output.bmp", &myClsId, NULL);
				image->Save(dlgFile.GetPathName(), &myClsId, NULL);
				delete image;
				GdiplusShutdown(gdiplusToken);
				::ReleaseDC(hDesktopWnd, hDesktopDC);
				DeleteDC(hCaptureDC);
				DeleteObject(hCaptureBitmap);

			}

		}
		catch (CFileException* pe) {
			CString error;
			error.Format(_T("File could not be saved, cause = %d\n"), pe->m_cause);
			AfxMessageBox(error);
			pe->Delete();
		}
	}


	

}
