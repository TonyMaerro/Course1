clc
clear
F = @(x) x.^3 + 2 * x + 4;

a = -2;
b = -1;
eps = 0.01;
ans1 = half(a,b,F);
ans2 = newton(a,F);
ans3 = iter(a, F);

function der = deffDer1(f) % производная
    der = matlabFunction(diff(f));
end

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

function x1 = iter(a, F)
    x0 = a;
    der = deffDer1(sym(F));
    M = 1.01 .* der(x0);
    f = @(x) x - F(x) ./ M;
    X(1) = 40;
    X(2) = 40130;
    x1 = f(x0);
    k = 3;
    while(abs(X(k-1) - X(k - 2)) >= eps)
        x0 = x1;
        x1 = f(x0);
        X(k) = x1;
        k = k + 1;
    end
end

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


