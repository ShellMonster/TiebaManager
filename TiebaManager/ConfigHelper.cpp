﻿/*
Copyright (C) 2015  xfgryujk
http://tieba.baidu.com/f?kw=%D2%BB%B8%F6%BC%AB%C6%E4%D2%FE%C3%D8%D6%BB%D3%D0xfgryujk%D6%AA%B5%C0%B5%C4%B5%D8%B7%BD

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "stdafx.h"
#include "ConfigHelper.h"
#include <MiscHelper.h>
#include "TBMConfig.h"
#include "TBMConfigPath.h"
#include "TiebaManager.h"
#include <TBMScan.h>
#include "ScanImage.h"
#include "TiebaManagerDlg.h"


// 保存当前账号配置
void SaveCurrentUserConfig()
{
	// 创建目录
	CreateDir(USERS_DIR_PATH + theApp.m_globalConfig->m_currentUser);

	// 当前账号配置
	theApp.m_userConfig->Save(USER_CONFIG_PATH);

	// Cookie
	theApp.m_cookieConfig->Save(COOKIE_PATH);

	// 历史回复、忽略ID等
	theApp.m_userCache->Save(CACHE_PATH);
}

// 设置当前账号
void SetCurrentUser(const CString& userName, BOOL save)
{
	// 保存当前账号配置
	if (save)
		SaveCurrentUserConfig();

	// 设置配置路径
	*theApp.m_globalConfig->m_currentUser = userName;
	CURRENT_USER_DIR_PATH = USERS_DIR_PATH + userName + _T("\\");
	USER_CONFIG_PATH = CURRENT_USER_DIR_PATH + _T("options.xml");
	COOKIE_PATH = CURRENT_USER_DIR_PATH + _T("ck.xml");
	CACHE_PATH = CURRENT_USER_DIR_PATH + _T("cache.xml");

	// 读取设置
	theApp.m_userConfig->Load(USER_CONFIG_PATH);
	// 方案
	theApp.m_plan->Load(OPTIONS_DIR_PATH + theApp.m_userConfig->m_plan + _T(".xml"));
	ReadImages(theApp.m_plan->m_imageDir, theApp.m_plan->m_images);
	// 贴吧名
	((CTiebaManagerDlg*)AfxGetApp()->m_pMainWnd)->m_forumNameEdit.SetWindowText(*theApp.m_userConfig->m_forumName);

	// Cookie
	theApp.m_cookieConfig->Load(COOKIE_PATH);

	// 历史回复、忽略ID等
	theApp.m_userCache->Load(CACHE_PATH);
}