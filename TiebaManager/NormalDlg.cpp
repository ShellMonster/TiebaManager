// NormalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NormalDlg.h"


// CNormalDlg �Ի���

IMPLEMENT_DYNAMIC(CNormalDlg, CDialog)

CNormalDlg::CNormalDlg(UINT nIDTemplate, CWnd* pParentWnd)
	: CDialog(nIDTemplate, pParentWnd),
	m_resize(this)
{

}

#pragma region MFC
CNormalDlg::~CNormalDlg()
{
}

void CNormalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNormalDlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_SIZE()
END_MESSAGE_MAP()
#pragma endregion

// CNormalDlg ��Ϣ��������

// ����Esc�رմ���
void CNormalDlg::OnCancel()
{
}

// ���λس��رմ���
void CNormalDlg::OnOK()
{
}

// ���ٴ���
void CNormalDlg::OnClose()
{
	DestroyWindow();

	CDialog::OnClose();
}

// �ı�ߴ�
void CNormalDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	m_resize.Resize();
}