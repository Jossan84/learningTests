function  xp=firstOrderFilter(t,x)

    u=5*sin(t)+random('Normal',t,t);
    a=3;
    b=3;
    xp=-a*x+b*u;
    
end
