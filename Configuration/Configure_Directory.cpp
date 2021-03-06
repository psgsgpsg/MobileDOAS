#include "stdafx.h"
#include "Configure_Directory.h"
using namespace Configuration;

IMPLEMENT_DYNAMIC(CConfigure_Directory, CPropertyPage)

CConfigure_Directory::CConfigure_Directory()
	: CPropertyPage(CConfigure_Directory::IDD)
{
	m_conf = nullptr;
}

CConfigure_Directory::~CConfigure_Directory()
{
	m_conf = nullptr;
}

void CConfigure_Directory::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);

	// The fit-parameters edit boxes
	DDX_Text(pDX, IDC_EDIT_DIRECTORY, m_conf->m_directory);
	DDX_Text(pDX, IDC_EDIT_SLEEP, m_conf->m_sleep);
	DDX_Text(pDX, IDC_EDIT_SKY_FILE, m_conf->m_defaultSkyFile);
	DDX_Text(pDX, IDC_EDIT_DARK_FILE, m_conf->m_defaultDarkFile);
	DDX_Text(pDX, IDC_EDIT_DARKCUR_FILE, m_conf->m_defaultDarkcurFile);
	DDX_Text(pDX, IDC_EDIT_OFFSET_FILE, m_conf->m_defaultOffsetFile);
}

BEGIN_MESSAGE_MAP(CConfigure_Directory, CPropertyPage)
	ON_EN_KILLFOCUS(IDC_EDIT_DIRECTORY, SaveData)
	ON_EN_KILLFOCUS(IDC_EDIT_SLEEP, SaveData)
	ON_EN_KILLFOCUS(IDC_EDIT_SKY_FILE, SaveData)
	ON_EN_KILLFOCUS(IDC_EDIT_DARK_FILE, SaveData)
	ON_EN_KILLFOCUS(IDC_EDIT_DARKCUR_FILE, SaveData)
	ON_EN_KILLFOCUS(IDC_EDIT_OFFSET_FILE, SaveData)
	ON_BN_CLICKED(IDC_BROWSE_DIRECTORY, &CConfigure_Directory::OnBnClickedBrowseDirectory)
	ON_BN_CLICKED(IDC_BROWSE_DIR_SKY, &CConfigure_Directory::OnBnClickedBrowseDirSky)
	ON_BN_CLICKED(IDC_BROWSE_DIR_DARK, &CConfigure_Directory::OnBnClickedBrowseDirDark)
	ON_BN_CLICKED(IDC_BROWSE_DIR_DARKCUR, &CConfigure_Directory::OnBnClickedBrowseDirDarkcur)
	ON_BN_CLICKED(IDC_BROWSE_DIR_OFFSET, &CConfigure_Directory::OnBnClickedBrowseDirOffset)
END_MESSAGE_MAP()

BOOL CConfigure_Directory::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	return TRUE;
}
void CConfigure_Directory::SaveData() {
	UpdateData(TRUE);
}

void Configuration::CConfigure_Directory::OnBnClickedBrowseDirectory()
{
	Common common;
	CString m_directory;
	if (common.BrowseForDirectory(m_directory)) {
		m_conf->m_directory = m_directory;
		UpdateData(FALSE);
	}
}


void Configuration::CConfigure_Directory::OnBnClickedBrowseDirSky()
{
	Common common;
	CString m_file;
	if (common.BrowseForFile("*.std", m_file)) {
		m_conf->m_defaultSkyFile = m_file;
		UpdateData(FALSE);
	}
}


void Configuration::CConfigure_Directory::OnBnClickedBrowseDirDark()
{
	Common common;
	CString m_file;
	if (common.BrowseForFile("*.std", m_file)) {
		m_conf->m_defaultDarkFile = m_file;
		UpdateData(FALSE);
	}
}


void Configuration::CConfigure_Directory::OnBnClickedBrowseDirDarkcur()
{
	Common common;
	CString m_file;
	if (common.BrowseForFile("*.std", m_file)) {
		m_conf->m_defaultDarkcurFile = m_file;
		UpdateData(FALSE);
	}
}


void Configuration::CConfigure_Directory::OnBnClickedBrowseDirOffset()
{
	Common common;
	CString m_file;
	if (common.BrowseForFile("*.std", m_file)) {
		m_conf->m_defaultOffsetFile = m_file;
		UpdateData(FALSE);
	}
}
