// Ejercicio de la burbuja

#include <stdio.h> 
#include <algorithm>    // std::swap
#include <vector>       // std::vector

int burbuja(int[]);

using namespace std;


int main(void) {

	int v1[20] = {11,14,17,18,2,12,13,4,5,35,3,1,6,7,8,9,10,16,15,19};

	int num = burbuja(v1);

	for (int i = 0; i < 20; i++) {
		printf_s("Posicion: %d \n", v1[i]);
	}

	printf_s("Pulse <Return> para finalizar...");
	getchar();

	return 0;
}
// Ordenación array descendente mediante algoritmo de la burbuja
int burbuja(int v1[]) {

	int cantidad = 20;
	int cont1 = 0;
	int cont2 = cantidad;

	__asm 
	{
		mov ebx, cantidad		; EBX -> Constante(20) | 32b
		mov eax, cont1			; EAX -> Incremental(0 a EBX(20)) del 1 bucle | 32b
		mov ecx, cont2			; ECX -> Decremental(20 a EAX(0 a 20)) del 2 bucle | 32b
		mov edx, v1				; EDX -> Contiene puntero al vector v1 | 32b

	Bucle1:
		cmp eax, ebx			; Comparación EAX(0 a EBX(20))
		je Fin					; True(EAX == EBX) -> Salir
		inc eax					; EAX++
		mov ecx, ebx			; Devolvemos valor EBX(20) a ECX
		jmp Bucle2				; Salto incondicional a Bucle2

	Bucle2:
		cmp ecx, eax			; Comparación ECX(20 a EAX(0 a 20))
		je Bucle1				; True(ECX == EAX) -> Bucle1
		dec ecx					; ECX--
		dec ecx					; ECX--
		mov edi, [edx + ecx * 4]; Guarda en EDI puntero con -> [EDX -> puntero v1 | ECX(20 a 0) -> Posición del vector * bits ]
		inc ecx					; ECX++
		mov esi, [edx + ecx * 4]; Guarda en ESI puntero con -> [EDX -> puntero v1 | ECX(20 a 0) -> Posición del vector * bits]
		cmp edi, esi			; Comparación EDI y ESI
		jl Intercambiar			; Si EDI < ESI salto a Intercambiar
		jmp Bucle2				; Salto incondicional a Bucle2

	Intercambiar:
		dec ecx					; ECX --
		mov [edx + ecx * 4], esi; SWAP del vector v1(n) -> ESI(v1(n-1)) 
		inc ecx					; ECX++
		mov [edx + ecx * 4], edi; SWAP del vector v1(n-1) -> EDI(v1(n))
		jmp Bucle2				; Salto incondicional a Bucle2

	Fin :

	}

	/*for (int i = 0; i < 20; i++) {

		for (int j = 20; j > i; j--) {

			if (v1[j - 1] < v1[j]) {
				swap(v1[j - 1], v1[j]);
			}
		}
	}*/

	return 0;
}