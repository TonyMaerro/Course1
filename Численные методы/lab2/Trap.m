a = 2;
b = 3;
n = 10;
f1 = @(x) sin(2.*x).*cos(x).*cos(x).*cos(x);
f2 = @(x) cos(5.*x)./x;
h = (b - a) ./ n;
S1 = (f1(a) + f1(b)) / 2;
S2 = (f2(a) + f2(b)) / 2;

for i = 1:(n-1)
    S1 = S1 + f1(a+i.*h);
    S2 = S2 + f2(a+i.*h);
end

S1 = h * S1;
S2 = h * S2;

integ1 = integral(f1, a, b);
integ2 = integral(f2, a, b);
    
absolute1 = abs(S1 - integ1);
otnos1 = absolute1 ./ integ1 * 100;
absolute2 = abs(S2 - integ2);
otnos12 = absolute2 ./ integ2 * 100;