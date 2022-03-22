X = [11 12 13 16 17 17 18 19 22 25];
Y = [-5 -9 -14 -19 -22 -28 -35 -38 -44 -50];
plot(X, Y)
N =  10;

sumX = 0;
sumX2 = 0;
sumY = 0;
sumXY = 0;

for i = 1:N
    sumX = sumX + X(i);
    sumX2 = sumX2 + (X(i))^2;
    sumY = sumY + Y(i);
    sumXY = sumXY + X(i).*Y(i);
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