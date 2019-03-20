#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t a,c,e,s,N;
unsigned long  f,i,k,n;
char cont_prog = 'n';

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set(p,x);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}
}

int main(void)
{
putchar ('\n');
printf("                     ***** RIESEL *****\n\n\n");
do {
mpz_t r;

printf("Enter the coefficient :");
scanf("%lu",&k);
printf("Enter the exponent :");
scanf("%lu",&n);

mpz_init(r);
mpz_init(a);
f=0;
mpz_init(e);
mpz_init(c);
mpz_ui_pow_ui(e,2,n);
mpz_set_ui(c,k);

if(mpz_cmp(c,e)<0)
{
if((k%42==3 && (n%3==0 || n%3==2))
|| (k%42==9 && (n%3==0)
|| (k%42==15 && n%3==1)
|| (k%42==27 && (n%3==1 || n%3==2))
|| (k%42==33 && (n%3==0 || n%3==1))
|| (k%42==39 && n%3==2)))
{
mpz_set_ui(a,5);
}
else if((k%10==1 && (n%4==2 || n%4==3 ))
|| (k%10==3 && (n%4==0 || n%4==3 ))
|| (k%10==7 && (n%4==1 || n%4==2 ))
|| (k%10==9 && (n%4==0 || n%4==1 )))
{
mpz_set_ui(a,3);
}
else
{
f=1;
printf("Enter another coefficient and exponent\n");
}

}
else
{
f=1;
printf("Coefficient must be less than 2^exponent\n");
}

if(f==0)
{
P(r,k,a);
mpz_init_set(s,r);

mpz_init(N);
mpz_ui_pow_ui(N,2,n);
mpz_mul_ui(N,N,k);
mpz_sub_ui(N,N,1);

for (i = 1; i <= n-2; i++)
{
mpz_pow_ui(s,s,2);
mpz_sub_ui(s,s,2);
mpz_mod(s,s,N);
}
mpz_clear(N);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu*2^%lu-1 is prime\n" , k,n);
}
else
{
printf("%lu*2^%lu-1 is composite\n" , k,n); 
}
mpz_clear(s);
}	
fflush(stdout);
getchar();//getchar();
//return 0;
printf("Do you want to start again? (y/n) : ");
cont_prog = getchar();

}
while (cont_prog == 'y' || cont_prog == 'Y');
return 0;
}