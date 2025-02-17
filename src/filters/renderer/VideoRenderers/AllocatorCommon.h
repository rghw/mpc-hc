/*
 * (C) 2003-2006 Gabest
 * (C) 2006-2013, 2017 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <d3d9.h>
#include <vmr9.h>
#include "../../../SubPic/ISubPic.h"
#include "PixelShaderCompiler.h"

// {4E4834FA-22C2-40e2-9446-F77DD05D245E}
DEFINE_GUID(CLSID_VMR9AllocatorPresenter,
            0x4e4834fa, 0x22c2, 0x40e2, 0x94, 0x46, 0xf7, 0x7d, 0xd0, 0x5d, 0x24, 0x5e);

// {B72EBDD4-831D-440f-A656-B48F5486CD82}
DEFINE_GUID(CLSID_DXRAllocatorPresenter,
            0xb72ebdd4, 0x831d, 0x440f, 0xa6, 0x56, 0xb4, 0x8f, 0x54, 0x86, 0xcd, 0x82);

// {C7ED3100-9002-4595-9DCA-B30B30413429}
DEFINE_GUID(CLSID_madVRAllocatorPresenter,
            0xc7ed3100, 0x9002, 0x4595, 0x9d, 0xca, 0xb3, 0xb, 0x30, 0x41, 0x34, 0x29);

DEFINE_GUID(CLSID_MPCVRAllocatorPresenter,
            0x28789E29, 0x5BDD, 0x4374, 0xAD, 0xEC, 0xAB, 0x2E, 0xB9, 0x21, 0x2C, 0x0D);

DEFINE_GUID(CLSID_EVRAllocatorPresenter,
            0x7612b889, 0xe070, 0x4bcc, 0xb8, 0x8, 0x91, 0xcb, 0x79, 0x41, 0x74, 0xab);

extern bool IsVMR9InGraph(IFilterGraph* pFG);
extern CString GetWindowsErrorMessage(HRESULT _Error, HMODULE _Module);
extern const wchar_t* GetD3DFormatStr(D3DFORMAT Format);

extern HRESULT CreateAP9(const CLSID& clsid, HWND hWnd, bool bFullscreen, ISubPicAllocatorPresenter** ppAP);
extern HRESULT CreateEVR(const CLSID& clsid, HWND hWnd, bool bFullscreen, ISubPicAllocatorPresenter** ppAP, bool isPreview = false);

// Set and query D3DFullscreen mode.
interface __declspec(uuid("8EA1E899-B77D-4777-9F0E-66421BEA50F8"))
    ID3DFullscreenControl :
    public IUnknown
{
    STDMETHOD(SetD3DFullscreen)(bool fEnabled) PURE;
    STDMETHOD(GetD3DFullscreen)(bool* pfEnabled) PURE;
};
