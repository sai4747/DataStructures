import cv2
import numpy as np
import os

def zip_to_video(zip_path, video_path, frame_width=256, frame_height=256, fps=1):
	# Read zip file as binary
	with open(zip_path, 'rb') as f:
		data = f.read()
	# Convert bytes to bits
	bits = ''.join(f'{byte:08b}' for byte in data)
	total_bits = len(bits)
	pixels_per_frame = frame_width * frame_height
	num_frames = (total_bits + pixels_per_frame - 1) // pixels_per_frame

	# Prepare video writer
	fourcc = cv2.VideoWriter_fourcc(*'mp4v')
	out = cv2.VideoWriter(video_path, fourcc, fps, (frame_width, frame_height), isColor=False)

	for i in range(num_frames):
		frame_bits = bits[i * pixels_per_frame : (i + 1) * pixels_per_frame]
		# Pad with zeros if needed
		frame_bits = frame_bits.ljust(pixels_per_frame, '0')
		frame = np.array([int(b) * 255 for b in frame_bits], dtype=np.uint8).reshape((frame_height, frame_width))
		out.write(frame)
	out.release()

def video_to_zip(video_path, zip_path):
	cap = cv2.VideoCapture(video_path)
	bits = ''
	while True:
		ret, frame = cap.read()
		if not ret:
			break
		# Convert frame to grayscale if needed
		if len(frame.shape) == 3:
			frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
		bits += ''.join(['1' if px > 127 else '0' for px in frame.flatten()])
	cap.release()
	# Convert bits to bytes
	byte_arr = bytearray()
	for i in range(0, len(bits), 8):
		byte = bits[i:i+8]
		if len(byte) < 8:
			break
		byte_arr.append(int(byte, 2))
	with open(zip_path, 'wb') as f:
		f.write(byte_arr)

# Example usage:
# zip_to_video('input.zip', 'output.mp4')
video_to_zip('output.mp4', 'recovered.zip')
