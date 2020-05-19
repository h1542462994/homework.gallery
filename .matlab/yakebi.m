clear
clc

% points
figure()
x1 = [1 3 4 5 6 7 8 9 10];
y1 = [10 5 4 2 1 1 2 3 4];
plot(x1,y1,'red*') 
% curve1
x = 1:0.01:10;
f = 0.267571*power(x,2)-3.60531*x+13.4597;
hold on
plot(x,f,'green-')
% min point1
px = 6.73712;
py = 1.31497;
hold on
plot(px,py,'green*')
% curve2
f = 0.00370528*power(x,3)+0.206761*power(x,2)-3.32876*x+13.1633;
hold on
plot(x,f,'blue-')
% min point2
px = 6.805;
py = 1.25338;
hold on
plot(px,py,'blue*')
% curve3
f = 0.000289249*power(x,8)-0.013851*power(x,7)+0.281965*power(x,6)-3.17443*power(x,5)+21.4797*power(x,4)-88.4999*power(x,3)+ 213.172*power(x,2)-268.214*x+134.969;
hold on
plot(x,f,'black-.')