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


 stx=median(stx')';
    sty=median(sty')';
    fit1=polyfit(stats1.Extrema(:,1),stats1.Extrema(:,2),1);
    m1=fit1(1);
    c1=fit1(2);
    xLeftTop=(500-c1)/m1;
    xLeftBottom=(700-c1)/m1;
    fitV1=polyval(fit1,[xLeftTop;xLeftBottom]);  %here the variables for the movable marker is defined as fit1 and fit2
    if(mod(i+2,3)==0)
        fit2=polyfit(stx,sty,1);
        fitV23=polyval(fit2,stx);
        m2=fit2(1);
        c2=fit2(2);
        xRighTop=(500-c2)/m2;
        xRightBottom=(700-c2)/m2;
        fitV2=polyval(fit2,[xRighTop;xRightBottom]);
    end
%     gray2=bwmorph(gray,'thin',20);
    red=poly2mask([xLeftTop,xLeftBottom,xRightBottom,xRighTop],[500,700,700,500],720,1280);
    mainframe(:,:,1)=imadd(double(mainframe(:,:,1)),double(100*red));  %this is the  part of the code where we are applying the red mask to the lane in whoch we are travveling
    figure(1);
    imshow(mainframe);hold on;
    title(i);
    [dir xi yi]=turnPridict(fit1,fit2);
    
     %fprintf(sport1,'%s',dir);