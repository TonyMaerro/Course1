X = [11 12 13 16 17 17 18 19 22 25];
Y = [-5 -9 -14 -19 -22 -28 -35 -38 -44 -50];
% X = [297 307 317 327 337 347 357 367];
% Y = [50.7 51.5 52.9 54.4 56.1 58.1 59.7 61.7];
plot(X, Y)
N = 10;

sumX = 0;
sumX2 = 0;
sumY = 0;
sumXY = 0;
sumX3 = 0;  
sumX4 = 0;
sumX2Y = 0;

for i = 1:N
    sumX = sumX + X(i);
    sumX2 = sumX2 + (X(i))^2;
    sumY = sumY + Y(i);
    sumXY = sumXY + X(i).*Y(i);
    
    sumX2Y = sumX2Y + (X(i))^2 .* Y(i);
    sumX3 = sumX3 + (X(i))^3;
    sumX4 = sumX4 + (X(i))^4;
end

a = (sumXY - (sumX .* sumY) ./ N) ./ (sumX2 - sumX.^2 ./ N);
b = (sumY - a .* sumX) ./ N;

f = Y;

for i = 1:N
    f(i) = a .* X(i) + b;
end

hold on;
plot(X, f);
hold off;

matr = [N sumX sumX2;
        sumX sumX2 sumX3;
        sumX2 sumX3 sumX4;];
    
invMatr = inv(matr);
sums = [sumY; sumXY; sumX2Y];

A = invMatr * sums;
a0 = A(1);
a1 = A(2);
a2 = A(3);

% for i = 1:3
%     a0 = a0 + invMatr(i) .* sums(i);
%     a1 = a1 + invMatr(i + 3) .* sums(i);
%     a2 = a2 + invMatr(i + 6) .* sums(i);
% end
F(10) = 1;
for i = 1:N
    F(i) = a0 + a1 .* X(i) + a2 .* (X(i))^2;
end
hold on;
plot(X, F);
hold off;
legend('first function', '-3.3779x + 31.0244', '48.6851 - 5.4932 .* x + 0.0498.* x^2') 