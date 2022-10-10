#pragma once

#define SAFE_DELETE(_pType)			if (_pType) { delete	_pType;		_pType = nullptr; }
#define SAFE_DELETE_ARRAY(_pType)	if (_pType) { delete[]	_pType;		_pType = nullptr; }
#define SAFE_RELEASE(_pType)		if (_pType) { _pType->Release();	_pType = nullptr; }