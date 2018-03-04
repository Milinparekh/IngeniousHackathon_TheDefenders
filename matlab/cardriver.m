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





 biggestBlob2=imerode(biggestBlob2,strel('disk',4));   %ersosion process
   
    stats1=regionprops(biggestBlob1,'Extrema');
    stats2=regionprops(biggestBlob2,'Extrema');
    stats2E=[];
    stx=[];sty=[];
    for j=1:size(stats2,1)
        stats2E=[stats2E;stats2(j).Extrema];
        stx=[stx,stats2(j).Extrema(:,1)];
        sty=[sty,stats2(j).Extrema(:,2)];
    end
    end