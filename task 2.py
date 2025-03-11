import cv2
import numpy as np
import matplotlib.pyplot as plt
from collections import Counter

def kmeans_segmentation(image, k=4):
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV) 
    pixels = hsv.reshape((-1, 3))
    pixels = np.float32(pixels)
    
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
    _, labels, centers = cv2.kmeans(pixels, k, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)
    
    segmented = centers[labels.flatten()].reshape(image.shape)
    segmented = np.uint8(segmented)
    return segmented, labels.reshape(image.shape[:2]), centers

def detect_road_region(segmented, labels):
    h, w = labels.shape
    road_mask = np.zeros((h, w), dtype=np.uint8)
    
    lower_half_labels = labels[h//2:]
    most_common_label = Counter(lower_half_labels.flatten()).most_common(1)[0][0]
    
    for row in range(h):
        for col in range(w):
            if labels[row, col] == most_common_label:
                road_mask[row, col] = 255
    return road_mask

def detect_lane_markings(segmented, road_mask):
    h, w, _ = segmented.shape
    white_mask = np.zeros((h, w), dtype=np.uint8)
    yellow_mask = np.zeros((h, w), dtype=np.uint8)
    
  
    road_outline = cv2.dilate(road_mask, np.ones((5, 5), np.uint8), iterations=3)
    non_road_mask = cv2.bitwise_not(road_mask)
    lane_region = cv2.bitwise_and(road_outline, non_road_mask)
    
   
    lane_pixels = segmented[lane_region == 255]
    lane_colors = Counter([tuple(pixel) for pixel in lane_pixels])
    common_colors = lane_colors.most_common(2)
    
    white_color = common_colors[0][0] if len(common_colors) > 0 else (255, 255, 255)
    yellow_color = common_colors[1][0] if len(common_colors) > 1 else (0, 255, 255)
    
    for row in range(h):
        for col in range(w):
            if lane_region[row, col] == 0:
                continue  
            
            pixel = tuple(segmented[row, col])
            
            if np.linalg.norm(np.array(pixel) - np.array(white_color)) < 50:  
                white_mask[row, col] = 255
            elif np.linalg.norm(np.array(pixel) - np.array(yellow_color)) < 50: 
                yellow_mask[row, col] = 255
    
    return white_mask, yellow_mask


image = cv2.imread('/content/Screenshot 2025-03-12 002421.png')
image = cv2.resize(image, (720, 480))
segmented, labels, centers = kmeans_segmentation(image)


road_mask = detect_road_region(segmented, labels)


plt.figure(figsize=(8, 4))
plt.imshow(cv2.cvtColor(segmented, cv2.COLOR_BGR2RGB))
plt.title("Segmented Image")
plt.axis("off")
plt.show()

plt.figure(figsize=(8, 4))
plt.imshow(road_mask, cmap='gray')
plt.title("Detected Road Region")
plt.axis("off")
plt.show()


white_mask, yellow_mask = detect_lane_markings(segmented, road_mask)


def show_mask(mask, title):
    plt.figure(figsize=(8, 4))
    plt.imshow(mask, cmap='gray')
    plt.title(title)
    plt.axis("off")
    plt.show()

show_mask(white_mask, "yellow Lane Markings")
show_mask(yellow_mask, "white Lane Markings")
