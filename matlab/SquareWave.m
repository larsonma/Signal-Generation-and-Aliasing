clear all
close all

fs = 8000; % sample rate is 8000 samples / second
Ts = 1/ fs; % time between samples is inverse of sample rate

%% Generate samples of a square wave
x1 = [1* ones(1 ,8) -1* ones(1 ,8)];
n = 1: length (x1 );

%% Plot discrete sequence
figure
stem (n,x1)

%% Visualize continuous signal with samples superimposed
figure
hold on
plot (n*Ts ,x1) % plot visualization of continuous signal
plot (n*Ts ,x1 ,'o') % plot sample points as open circles