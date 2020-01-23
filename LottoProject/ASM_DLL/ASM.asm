.code
;RCX data
;RDX start index
;R8 data length
;R9 test

MyProc1 proc ;RCX: dword, RDX: dword

mov R8,RDX							;zapisanie adresu wewnetrznej tablicy w rejestrze R8

xor edx,edx							;wyzerowanie licznika glownego

xor eax,eax							;zerowanie licznika zewnetrznego
push rax							;umieszczenie na stosie licznika zewnetrznego

xor ebx,ebx							;zerowanie licznika wewnetrznego
push rbx							;umieszczenie na stosie licznika wewnetrznego


ZewnetrznaPetla:

pop rbx								;pobranie licznika wewnetrznego ze stosu
pop rax								;pobranie licznika zewnetrznego ze stosu
xor ebx,ebx							;zerowanie licznika wewnetrznego
push rax							;umieszczenie licznika zewnetrznego na stosie
push rbx							;umieszczenie licznika wewnetrznego na stosie
cmp eax,6							;sprawdzenie czy nastapil koniec zewnetrznej tablicy
je Koniec							;jesli tak to skok do etykiety Koniec

WewnetrznaPetla:

pop rbx								;pobranie licznika wewnetrznego ze stosu
pop rax								;pobranie licznika zewnetrznego ze stosu
push rax							;umieszczenie licznika zewnetrznego na stosie
push rbx							;umieszczenie licznika wewnetrznego na stosie
cmp ebx,6							;sprawdzenie czy nastapil koniec wewnetrznej tablicy
je IncLicznikZewnetrzny				;jesli tak to skok do etykiety IncLicznikZewnetrzny

imul rax,4							;licznik zewnetrzny*4 aby uzyskac przesuniecie w adresach
imul rbx,4							;licznik wewnetrzny*4 aby uzyskac przesuniecie w adresach
add rax,RCX							;dodanie do przesuniecia adresu poczatku zewnetrznej tablicy
add rbx,R8							;dodanie do przesuniecia adresu poczatku wewnetrznej tablicy
mov eax,[rax]						;odczytanie wartosci zewnetrznej tablicy
mov ebx,[rbx]						;odczytanie wartosci wewnetrznej tablicy

cmp eax,ebx							;porownanie liczb z zewenetrznej oraz wewnetrznej tablicy			
je Dodaj							;jesli rowne to skok do etykiety Dodaj

Dalej:

pop rbx								;pobranie licznika wewnetrznego ze stosu
pop rax								;pobranie licznika zewnetrznego ze stosu
add ebx,1							;inkrementacja licznika wewnetrznego
push rax							;umieszczenie licznika zewnetrznego na stosie
push rbx							;umieszczenie licznika wewnetrznego na stosie

jmp WewnetrznaPetla


Dodaj:	

add edx,1							;inkrementacja licznika glownego
jmp Dalej							;skok do etykiety Dalej

IncLicznikZewnetrzny:

pop rbx								;pobranie licznika wewnetrznego ze stosu
pop rax								;pobranie licznika zewnetrznego ze stosu
add eax,1							;inkrementacja licznika zewnetrznego
push rax							;umieszczenie licznika zewnetrznego na stosie
push rbx							;umieszczenie licznika wewnetrznego na stosie

jmp ZewnetrznaPetla

Koniec:

pop rbx								;pobranie licznika wewnetrznego ze stosu
pop rax								;pobranie licznika zewnetrznego ze stosu
xor eax,eax							;wyzerowanie licznika zewnetrznego

mov rax,rdx							;zwrocenie liczby trafien
ret									;koniec

MyProc1 endp

MyProc2 proc C ;RCX: dword, RDX: dword, R8: dword

mov R9,rdx

xor edx,edx							;wyzerowanie rejestru edx
mov rax,R8							;zapisanie poli pienieznej do rejestru eax
mov ebx,100							;zapisanie liczby 100 do rejestru ebx (dzielnik)
div ebx								;podzielenie zawartosci eax przez ebx
imul eax,44							;pomno¿enie poli pienieznej przez 44 (dzielna)
push rax							;zapisanie sumy pienieznej dla wartosci 6 na stosie

mov rbx,RCX							;pobranie adresu pierwszego elementu tablicy
mov ebx,[rbx]						;pobranie wartosci spod adresu
cmp ebx,0							;sprawdzenie czy ta wartosc rowna sie zero
je UstawZeroSzostka					;jesli tak to skok do etykiety UstawZeroSzostka

div ebx								;jesli nie to podziel zawartosc eax przez ebx	
mov rbx,R9							;pobranie adresu pierwszego elementu tablicy
mov [rbx],eax						;zapisanie podzielonej liczby na pierwszym miejscu tablicy

KoniecSzostka:

xor edx,edx							;wyzerowanie rejestru edx
mov rax,R8							;zapisanie poli pienieznej do rejestru eax
mov ebx,100							;zapisanie liczby 100 do rejestru ebx (dzielnik)
div ebx								;podzielenie zawartosci eax przez ebx
imul eax,8							;pomno¿enie poli pienieznej przez 8 (dzielna)
push rax							;zapisanie sumy pienieznej dla wartosci 5 na stosie

mov rbx,4							;przesuniecie na drugi element tablicy
add rbx,RCX							;pobranie adresu drugiego elementu tablicy
mov ebx,[rbx]						;pobranie wartosci spod adresu
cmp ebx,0							;sprawdzenie czy ta wartosc rowna sie zero
je UstawZeroPiatka					;jesli tak to skok do etykiety UstawZeroPiatka

div ebx								;jesli nie to podziel zawartosc eax przez ebx	
mov rbx,4							;przesuniecie na drugi element tablicy
add rbx,R9							;pobranie adresu drugiego elementu tablicy
mov [rbx],eax						;zapisanie podzielonej liczby na drugim miejscu tablicy

KoniecPiatka:

mov rbx,12							;przesuniecie na czwarty element tablicy
add rbx,RCX							;pobranie adresu czwartego elementu tablicy
mov ebx,[rbx]						;pobranie wartosci spod adresu
cmp ebx,0							;sprawdzenie czy ta wartosc rowna sie zero
je UstawZeroTrojka					;jesli tak to skok do etykiety UstawZeroTrojka

mov eax,24							;zapisanie wartosci 24 w rejestrze eax
imul eax,ebx						;pomnozenie rejestru eax przez ebx
push rax							;zapisanie sumy pienieznej dla wartosci 3 na stosie

mov eax,24							;zapisanie wartosci 24 w rejestrze eax
mov rbx,r9							;przesuniecie na czwarty element tablicy
add rbx,12							;pobranie adresu czwartego elementu tablicy
mov [rbx],eax						;zapisanie wartosci spod rejestru eax na czwartym elemencie tablicy


KoniecTrojka:

xor edx,edx							;wyzerowanie rejestru edx
mov rax,R8							;zapisanie poli pienieznej w rejestrze eax
pop rbx								;pobranie ze stosu sumy pienieznej dla wartosci 3
sub eax,ebx							;odjecie od puli pienieznej sumy pienieznej dla wartosci 3
pop rbx								;pobranie ze stosu sumy pienieznej dla wartosci 5
sub eax,ebx							;odjecie od puli pienieznej sumy pienieznej dla wartosci 5
pop rbx								;pobranie ze stosu sumy pienieznej dla wartosci 6
push rbx							;zapisanie na stos sumy pienieznej dla wartosci 6
sub eax,ebx							;odjecie od puli pienieznej sumy pienieznej dla wartosci 6


mov rbx,8							;przesuniecie na trzeci element tablicy
add rbx,RCX							;pobranie adresu trzeciego elementu tablicy
mov ebx,[rbx]						;pobranie wartosci spod adresu
cmp ebx,0							;sprawdzenie czy ta wartosc rowna sie zero
je UstawZeroCzworka					;jesli tak to skok do etykiety UstawZeroCzworka


div ebx								;jesli nie to podziel zawartosc eax przez ebx	
mov rbx,8							;przesuniecie na trzeci element tablicy
add rbx,R9							;pobranie adresu trzeciego elementu tablicy
mov [rbx],eax						;zapisanie podzielonej liczby na trzecim miejscu tablicy

KoniecCzworka:

mov rbx,RCX							;pobranie adresu pierwszego elementu tablicy
mov ebx,[rbx]						;pobranie wartosci spod adresu
cmp ebx,0							;sprawdzenie czy ta wartosc rowna sie zero
je ZwrocPuleSzostki					;jesli tak to skok do etykiety UstawZeroSzostka

mov rax,0							;zapisanie wartosci zero w rejestrze eax
ret									;koniec

UstawZeroSzostka:

mov rbx,R9							;pobranie adresu pierwszego elementu tablicy
mov [rbx],edx						;zapisanie zera na pierwszym miejscu tablicy
jmp KoniecSzostka					;skok do etykiety KoniecSzostka

UstawZeroPiatka:

mov rbx,4							;przesuniecie na drugi element tablicy
add rbx,R9							;pobranie adresu drugiego elementu tablicy
mov [rbx],edx						;zapisanie zera na drugim miejscu tablicy
jmp KoniecPiatka					;skok do etykiety KoniecPiatka

UstawZeroTrojka:

mov rbx,12							;przesuniecie na czwarty element tablicy
add rbx,R9							;pobranie adresu czwartego elementu tablicy
mov [rbx],edx						;zapisanie zera na czwartym miejscu tablicy
push rdx							;zapisanie sumy pienieznej dla wartosci 3 na stosie
jmp KoniecTrojka					;skok do etykiety KoniecTrojka

UstawZeroCzworka:

mov rbx,8							;przesuniecie na trzeci element tablicy
add rbx,R9							;pobranie adresu trzeciego elementu tablicy
mov [rbx],edx						;zapisanie zera na trzecim miejscu tablicy
push rdx							;zapisanie sumy pienieznej dla wartosci 4 na stosie
ret
jmp KoniecCzworka					;skok do etykiety KoniecCzworka

ZwrocPuleSzostki:

pop rax								;pobranie ze stosu sumy pienieznej dla wartosci 6
ret									;koniec

MyProc2 endp

end