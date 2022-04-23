#pragma once

//cdevl Вызов : _cdecl
//Параметры : все по значению, три параметра(int)
//Возврат : сумма значений всех параметров(int).
// 
//cstd Вызов : _stdcall
//Параметры : 1 по ссылке, 2 по значению(int)
//Возврат : произведение значений всех параметров(int).
// 
//cfst Вызов : _fastcall
//Параметры : все по значению, четыре параметра(int)
//Возврат : сумма значений всех параметров(int).

namespace Call {
	int _cdecl cdevl(int, int, int);
	int _stdcall cstd(int, int, int);
	int _fastcall cfst(int, int, int);
};

