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