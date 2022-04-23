clc
clear
F = @(x) x.^3 + 2 * x + 4;
X = linspace(-2, -1);
plot(X, F(X));
a = 0;
b = 2;
eps = 0.001;

ans2 = newton(a, F);
ans3 = iter(a, F);
% Метод деления пополам
ans1 = half(a,b,F);
function x = half(a, b, F)
k = 1;
x = ( a + b ) ./ 2;
if((F(a) * F(x)) < 0)
    b = x;
else
    a = x;
end

k = k + 1;

while(abs(b - a) >= eps)
    x = ( a + b ) ./ 2;
    if((F(a) * F(x)) < 0)
        b = x;
    else
        a = x;
    end
     k = k + 1;
end
 
end
% Метод Ньютона

function x = newton(a, F)
der = deffDer1(sym(F));
x = a;
h = F(x) ./ der(x);
x = x - h;
while (abs(h)> eps)
    h = F(x) ./ der(x);
    x = x - h; 
end
end
% Метод простой итерации

function x = iter(a, F)
x0 = a;
der = derDeff1(sym(F));
M = @(x0) 1.01 .* der(x0);
M(a)
f = @ (x) x - F(x) ./ M(x);
X(1) = 40;
X(2) = 40130;
x = x0;
x1 = f(x0);
k = 3;
while(abs(X(k-1) - X(k - 2)) >= eps)
    x0 = x1;
    x1 = f(x0);
    X(k) = x1;
    k = k + 1;
end
end
% deffDer1();
function der = deffDer1(f) % производная
 %   syms x;
%     f = x.^3 + 2.*x + 4;
%     syms der1;
    der = matlabFunction(diff(f));
%     der2 = matlabFunction(diff(f, 2));
end
