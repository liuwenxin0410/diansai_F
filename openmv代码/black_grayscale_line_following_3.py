# Hello World Example
#
# Welcome to the OpenMV IDE! Click on the green run arrow button below to run the script!

import pyb, sensor, image, math, time
from pyb import UART
import json
from pid import PID
rho_pid = PID(p=0.4, i=0)
theta_pid = PID(p=0.001, i=0)

uart = UART(3,115200)
GRAYSCALE_THRESHOLD = [(65, 0, 19, 100, -128, 113)]
THRESHOLD = (0, 99, -128, 18, -110, 124) # Grayscale threshold for dark things...

led = pyb.LED(3)
usb = pyb.USB_VCP()
led.on()

roi_1 = [(20, 0, 120, 20),         #  北
            (20, 100, 120, 20),     # 南
            (0, 0, 20, 120),        #  西
            (140, 0, 20, 120),      #  东
            (60,40,40,40)]          #   中

sensor.reset() # 初始化摄像头
#sensor.set_pixformat(sensor.GRAYSCALE) # 格式为 RGB565.
sensor.set_pixformat(sensor.GRAYSCALE) # 格式为 RGB565.
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(20) # 跳过10帧，使新设置生效
sensor.set_auto_whitebal(False) # turn this off.
sensor.set_auto_gain(False) # must be turned off for color tracking
clock = time.clock()




low_threshold = (255, 144                         )

buf =[0 for i in range(5)]

DI =[0 for i in range(8)]
DI1 =[0 for i in range(8)]
uart.init(115200, bits=8, parity=None, stop=1)


red =(65, 0, 19, 100, -128, 113)
img=sensor.snapshot()
red_blobs = img.find_blobs([red])

color_blobs = img.find_blobs([red])




while(True):
        m = -1
        isten = 0
        #img = sensor.snapshot()
        img = sensor.snapshot().lens_corr(strength = 1.8, zoom = 1.0)

        img.binary([low_threshold],invert = 0)#二值化
        for r in roi_1:
            m += 1
            blobs = img.find_blobs(GRAYSCALE_THRESHOLD, roi=r[0:4],pixels_threshold=100, area_threshold=100, merge=True)
            #img.draw_rectangle(r[0:4], color=(255,0,0))
            if blobs:
                most_pixels = 0
                largest_blob = 0
                for i in range(len(blobs)):
                #目标区域找到的颜色块（线段块）可能不止一个，找到最大的一个，作为本区域内的目标直线
                    if blobs[i].pixels() > most_pixels:
                        most_pixels = blobs[i].pixels()
                        #merged_blobs[i][4]是这个颜色块的像素总数，如果此颜色块像素总数大于
                        largest_blob = i
                # Draw a rect around the blob.
                img.draw_rectangle(blobs[largest_blob].rect())
                #将此区域的像素数最大的颜色块画矩形和十字形标记出来
                img.draw_cross(blobs[largest_blob].cx(),
                               blobs[largest_blob].cy())
                buf[m] = 1
            else:
                buf[m] = 0

        for i in range(0, 160, 20):
            k = int(i/20)
            roi2 = (i, 0, 20, 20)
            img.draw_rectangle((i, 0, 20, 20), color=(0,255,0))
            blobs = img.find_blobs(GRAYSCALE_THRESHOLD, roi=roi2, pixels_threshold=100, area_threshold=100,merge=True)
            if blobs:
                for n in range(len(blobs)):
                #目标区域找到的颜色块（线段块）可能不止一个，找到最大的一个，作为本区域内的目标直线
                   if blobs[n].pixels() > most_pixels:
                       most_pixels = blobs[n].pixels()
                       #merged_blobs[i][4]是这个颜色块的像素总数，如果此颜色块像素总数大于
                       largest_blob = n
                   DI1[k] = 1
            else:
                DI1[k] = 0

        for i in range(0, 160, 20):
            k = int(i/20)
            roi2 = (i, 55, 20, 20)
            img.draw_rectangle((i, 55, 20, 20), color=(0,255,0))
            blobs = img.find_blobs(GRAYSCALE_THRESHOLD, roi=roi2, pixels_threshold=100, area_threshold=100,merge=True)
            if blobs:
                for n in range(len(blobs)):
                #目标区域找到的颜色块（线段块）可能不止一个，找到最大的一个，作为本区域内的目标直线
                   if blobs[n].pixels() > most_pixels:
                       most_pixels = blobs[n].pixels()
                       #merged_blobs[i][4]是这个颜色块的像素总数，如果此颜色块像素总数大于
                       largest_blob = n
                   DI[k] = 1
            else:
                DI[k] = 0

        if buf[0]==1 and buf[1] ==1 and buf[2] ==1 and buf[3] ==1 and buf[4] ==1:
            isten = 1

        data = bytearray([0xb3,0xb3,DI[0],DI[1],DI[2],DI[3],DI[4],DI[5],DI[6],DI[7],isten,0x0b,0x0a])  #打包要发送的数据
        uart.write(data)  #串口发送
        print(DI)

