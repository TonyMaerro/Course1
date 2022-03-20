% Метод симпсона
a = 2;
b = 3;
n = 10;
fun1 = @(x) sin(2.*x).*cos(x).*cos(x).*cos(x);
fun2 = @(x) cos(5.*x)./x;
h = (b-a)./n;   
i = 1;
x = a;
F1 = fun1(x);
F2 = fun2(x);
S1 = F1;
S2 = F2;
x = x+h;
F1 = fun1(x);
F2 = fun2(x);

S1 = S1 + 4.*F1;
S2 = S2 + 4.*F2;
i=i+2;

while(i < n)
    x = x+h;
    F1 = fun1(x);
    F2 = fun2(x);
    S1 = S1 + 2.*F1;
    S2 = S2 + 2.*F2;
    x = x+h;
    F1 = fun1(x);
    F2 = fun2(x);
    S1 = S1 + 4.*F1;
    S2 = S2 + 4.*F2;
    i=i+2;
end

x=b;
F1 = fun1(x);
F2 = fun2(x);
S1 = (S1 + F1).*h/3;
S2 = (S2 + F2).*h/3;

iteg1 = quad('sin(2.*x).*(cos(x)).^3', a, b, h);
iteg2 = quad('cos(5.*x)./x', a, b, h);


absolut1 = abs(S1 - iteg1);
otnos1 = absolut1./iteg1 * 100;

absolut2 = abs(S2 - iteg2);
otnos2 = absolut2./iteg2 * 100;




