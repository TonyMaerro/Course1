a = 2;
b = 3;
n = 10;
k = 1 / 2;
h = (b - a) ./ n;
a = a + k .* h;
S1 = 0;
S2 = 0;
f1 = @(x) sin(2.*x).*cos(x).*cos(x).*cos(x);
f2 = @(x) cos(5.*x)./x;
integ1 = integral(f1, a, b);
integ2 = integral(f2, a, b);
  
for i = 0:(n-1)
    S1 = S1 + f1(a + i .* h);
    S2 = S2 + f2(a + i .* h);
end

S1 = h.*S1;
S2 = h.*S2;

absolute1 = abs(S1 - integ1);
otnos1 = absolute1 ./ integ1 * 100;
absolute2 = abs(S2 - integ2);
otnos2 = absolute2 ./ integ2 * 100;