clear all
close all

fs = 16000; % sample rate is 8000 samples / second
Ts = 1/ fs; % time between samples is inverse of sample rate
t_max = 0.01; % max time is 0.01 seconds
n_max = t_max /Ts; % determine largest index
n = 0:1: n_max ; % generate index vector

%% Generate samples of sinusoid
frequency = 7000; % in Hz
x1 = sin (2* pi* frequency *( Ts*n ));

%% Plot discrete sequence
figure
stem (n,x1)

%% Visualize continuous signal
figure
plot (n*Ts ,x1)