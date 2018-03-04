#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 2  // 方程式の数

double omega_0, omega, A;
double f(double t, double x[],int i){
  if(i == 0) return x[1]; // dx[0]/dt = dx/dt
  if(i == 1) return (-1 * omega_0 * omega_0 * x[0] + A * cos(omega * t)); // dx[1]/dt = dv/dt
}

double x[N];
void Rungen_Kutta(double t, double dt){
  double k1[N], k2[N], k3[N], k4[N];
  double t1[N], t2[N], t3[N];
  double h = dt * 0.5;
  // k1
  for(int i = 0; i < N; i++){
    k1[i] = f(t, x, i) * dt;
    t1[i] = x[i] + 0.5 * k1[i];
  }
  // k2
  for(int i = 0; i < N; i++){
    k2[i] = f(t + h, t1, i) * dt;
    t2[i] = x[i] + 0.5 * k2[i];
  }
  // k3
  for(int i = 0; i < N; i++){
    k3[i] = f(t + h, t2, i) * dt;
    t3[i] = x[i] + k3[i];
  }
  // k4
  for(int i = 0; i < N; i++) k4[i] = f(t + dt, t3, i) * dt;

  for(int i = 0; i < N; i++) x[i] += (k1[i] + 2*(k2[i] + k3[i]) + k4[i]) / 6.0;
}

int main(){

   double t, v0, dt, h, max;
   // 初期値
   t = 0.0, v0 = 1.0;
   x[0] = 1.0; // 初期位置
   x[1] = v0; // 初期速度

   max = 10.0; // 区間の終わり
   dt = 0.01; // 刻み幅
   omega_0 = 5.0; // 調和振動子の角振動数
   omega = 5.0; // 強制振動の角振動数(適宜変更)
   A = 10.0; // 振幅
   printf("%.15e　%.15e %.15e\n", t, x[0], x[1]);
   while(t <= max){
     Rungen_Kutta(t, dt);
     t += dt;
     printf("%.15e　%.15e %.15e\n", t, x[0], x[1]);
   }
   return 0;
}
