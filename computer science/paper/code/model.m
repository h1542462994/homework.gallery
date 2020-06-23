%--------------------------------------------------------------------------
%   初始化
%--------------------------------------------------------------------------
clear;clc;

%--------------------------------------------------------------------------
%   参数设置
%--------------------------------------------------------------------------
N = 10000;                                                                  %人口总数
E = 0;                                                                      %潜伏者
I = 1;                                                                      %传染者
S = N - I;                                                                  %易感者
R = 0;                                                                      %康复者

r = 20;                                                                     %感染者接触易感者的人数
B = 0.03;                                                                   %传染概率
a = 0.1;                                                                    %潜伏者转化为感染者概率
r2 = 20;                                                                    %潜伏者接触易感者的人数
B2 = 0.03;                                                                  %潜伏者传染正常人的概率
y = 0.1;                                                                    %康复概率

T = 1:140;
for idx = 1:length(T)-1
    S(idx+1) = S(idx) - r*B*S(idx)*I(idx)/N(1) - r2*B2*S(idx)*E(idx)/N;
    E(idx+1) = E(idx) + r*B*S(idx)*I(idx)/N(1)-a*E(idx) + r2*B2*S(idx)*E(idx)/N;
    I(idx+1) = I(idx) + a*E(idx) - y*I(idx);
    R(idx+1) = R(idx) + y*I(idx);
    
end

plot(T,S,T,E,T,I,T,R);grid on;
xlabel('天');ylabel('人数')
legend('易感者','潜伏者','传染者','康复者')