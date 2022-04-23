matr = [1 2 3 4;
        1 2 2 2;
        2 3 4 4;
        3 4 5 6];
free = [2;
        4;
        7;
        9];

    a = matr(2, 1);
ansv1 = methodInvMatr(matr, free);

    
    function reply = methodInvMatr(matr, free)
        invMatr = inv(matr);
        reply = invMatr .* free;
    end
    
  