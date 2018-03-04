clear all;
close all;
clc;


sport1 = serial('COM16','BAUD',9600);    %coom  port setup 
 fopen(sport1);
cd ..;
video=VideoReader('input/project_video.mp4');  %giving the apth for th input video
numberToExtract=2;

cd output/;

vidWriter=VideoWriter('Result.avi'); %setting the path for the storing of the out put video

vidWriter.FrameRate=30;

cd ..;

open(vidWriter);


cd code;
rectI=zeros(720,720);
trap=[178 720; 552 450; 728 450; 1280 720];
rect=[475 720; 475 0; 800 0; 800 720];
c = [552 178 1280 728];
r = [450 720 720 450];
BW = poly2mask(c,r,720,1280);