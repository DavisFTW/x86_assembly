#include <iostream>

__declspec(naked) int function(int a, int b)
{
	__asm
	{
		push ebp;
		mov  ebp, esp;
		mov  ebx, [ebp + 4];
		mov  eax, [ebp + 8];
		add  eax, [ebp + 12];
		sub  eax, 2;
		imul eax, 2;
		pop  ebp;
		jmp ebx;
	}
}

__declspec(naked) int subtract(int a)
{
	__asm
	{
		push ebp;
		mov  ebp, esp;
		mov eax, [ebp + 8];
		sub eax, 7;
		pop  ebp;
		ret 4;
	}
}

__declspec(naked) int multiply(int a)
{
	__asm
	{
		push ebp;
		mov  ebp, esp;
		mov  eax, [ebp + 8];
		imul eax, 2;
		pop  ebp;
		push eax;
		call subtract;
		ret 4;
	}
}

__declspec(naked) int addition(int a, int b)
{
	__asm
	{
		push ebp; 
		mov  ebp, esp;
		mov  eax, [ebp + 8]; 
		add  eax, [ebp + 12];
		pop ebp;
		push eax;
		call multiply;
		ret 8;
	}

}


int main()
{
	int answer = 0;

	__asm
	{
		push 5;
		push 2;
		call function;
		mov  answer, eax;
		add  esp, 12;
	}

	std::cout << answer << std::endl;
}