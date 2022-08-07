;
; Ejemplo9_Assembler.asm
;
; Created: 28/05/2022 15:43:34
; Author : Godo Sanchez
;


;etiquetas para los numeros
.equ Led1=5
.equ Led2=4
.equ Boton=7
;etiquetas para los registros
.def Wtrabajo = R16
.def delay_0 = R17
.def delay_1 = R18
.def contador = R19
;Definiciones
ldi delay_0,250
ldi delay_1,100

//pwm
//ldi DDRD,0XFF ;DEFINMOS COMO SALIDA

ldi Wtrabajo, 1<<WGM00 | 1<<WGM01  | 1<<WGM02| 1<<COM0A1 ;FAST PWM
out TCCR0A,Wtrabajo
ldi Wtrabajo,1<<CS01
out TCCR0B,Wtrabajo

ldi contador,0x00

;while(1)

;1 al ddrb pin5


sbi DDRB,Led1
cbi DDRB,Boton
ldi Wtrabajo,0xFF
out DDRD,Wtrabajo
LDI Wtrabajo,1<<WGM01 | 1<<WGM00 | 1<<COM0A1 ;MODO FAST PWM
out TCCR0A,Wtrabajo
ldi Wtrabajo,1<<CS01;clok FCY/8
out TCCR0B,Wtrabajo

ldi contador,0x00

Bucle:
ldi delay_0,250
ldi delay_1,100

out OCR0A,contador
INC contador

RCALL delay

rjmp Bucle


/*
sbi PORTB,Led1
call _delay
call _delay
call _delay
call _delay
cbi PORTB,Led1
call _delay
call _delay
call _delay
call _delay*/


//subrutina para el delay

_delay:
dec delay_0
brne _delay
dec delay_1
brne _delay


ret

delay:
dec delay_0
brne delay

dec delay_1
brne delay

ret