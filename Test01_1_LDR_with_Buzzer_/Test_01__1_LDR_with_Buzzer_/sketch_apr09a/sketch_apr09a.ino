/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


// notes in the melody:
int melody[] = {
   126, 126, 231, 245, 187, 64, 0, 0, 15, 92, 131, 146, 177, 215, 224, 213, 203, 182, 155, 136, 97, 39, 24, 85, 177, 239, 244, 169, 40, 0, 0, 27, 95, 123, 144, 184, 219, 224, 217, 205, 179, 157, 136, 86, 30, 31, 104, 190, 246, 242, 149, 22, 0, 0, 42, 97, 121, 150, 194, 221, 221, 216, 198, 173, 160, 137, 80, 31, 49, 125, 204, 253, 230, 124, 2, 0, 0, 50, 94, 117, 155, 200, 220, 222, 218, 196, 177, 167, 133, 67, 28, 60, 133, 211, 253, 212, 100, 0, 0, 0, 58, 93, 119, 165, 205, 219, 224, 213, 189, 178, 168, 123, 56, 34, 77, 151, 228, 255, 198, 81, 0, 0, 11, 61, 87, 121, 170, 203, 218, 222, 204, 182, 177, 164, 108, 46, 39, 87, 166, 239, 253, 182, 61, 0, 0, 24, 63, 87, 128, 173, 200, 217, 216, 194, 178, 179, 156, 91, 41, 46, 100, 183, 249, 247, 161, 43, 0, 0, 34, 63, 91, 136, 175, 202, 218, 210, 186, 179, 180, 143, 76, 37, 50, 115, 201, 255, 242, 143, 30, 0, 1, 38, 61, 97, 142, 178, 208, 220, 204, 182, 182, 175, 124, 60, 28, 50, 123, 209, 255, 224, 119, 18, 0, 16, 44, 68, 107, 147, 182, 210, 215, 192, 178, 185, 169, 113, 53, 28, 60, 136, 221, 255, 207, 97, 8, 0, 20, 43, 72, 113, 154, 192, 219, 215, 188, 182, 186, 157, 98, 42, 25, 65, 148, 233, 255, 190, 80, 10, 6, 24, 45, 76, 116, 158, 200, 224, 207, 185, 187, 184, 148, 87, 35, 28, 74, 162, 240, 245, 166, 62, 12, 13, 28, 49, 82, 121, 166, 210, 223, 199, 185, 191, 182, 140, 77, 32, 32, 86, 176, 244, 233, 143, 51, 15, 16, 29, 52, 84, 123, 173, 216, 218, 195, 190, 197, 181, 130, 68, 29, 35, 98, 190, 248, 218, 123, 46, 18, 19, 31, 56, 89, 132, 187, 223, 213, 194, 195, 200, 178, 123, 64, 30, 46, 118, 210, 252, 201, 106, 40, 17, 17, 31, 57, 89, 138, 196, 220, 206, 194, 199, 200, 170, 114, 56, 26, 52, 131, 221, 246, 183, 96, 41, 22, 22, 39, 61, 92, 147, 201, 214, 200, 194, 203, 199, 162, 105, 50, 30, 66, 155, 238, 241, 169, 91, 43, 23, 25, 41, 60, 97, 159, 205, 210, 197, 196, 207, 197, 157, 97, 46, 32, 80, 178, 247, 230, 156, 87, 42, 23, 27, 39, 57, 103, 166, 203, 201, 190, 196, 204, 190, 147, 88, 41, 36, 99, 198, 250, 218, 147, 83, 43, 27, 32, 38, 58, 113, 172, 201, 195, 189, 198, 204, 185, 138, 81, 37, 43, 120, 215, 248, 207, 139, 80, 42, 33, 34, 36, 65, 123, 179, 199, 191, 187, 196, 199, 176, 129, 72, 32, 54, 143, 229, 245, 197, 131, 73, 41, 34, 29, 33, 70, 132, 183, 194, 187, 186, 196, 195, 169, 122, 62, 29, 67, 162, 235, 237, 188, 125, 70, 45, 36, 27, 35, 78, 141, 183, 189, 183, 186, 195, 190, 162, 112, 51, 29, 84, 180, 240, 231, 181, 116, 66, 46, 32, 23, 36, 87, 149, 183, 186, 182, 187, 193, 185, 155, 99, 41, 34, 103, 194, 238, 224, 171, 107, 67, 47, 31, 21, 42, 99, 156, 183, 183, 181, 189, 192, 180, 147, 85, 30, 40, 120, 201, 233, 214, 157, 100, 65, 45, 27, 20, 50, 111, 163, 182, 181, 184, 191, 192, 180, 140, 73, 25, 52, 135, 206, 232, 204, 146, 95, 66, 46, 24, 22, 60, 121, 166, 180, 181, 186, 191, 190, 176, 128, 56, 22, 65, 146, 211, 228, 192, 135, 91, 65, 42, 19, 23, 68, 128, 168, 179, 183, 189, 193, 194, 175, 117, 46, 28, 79, 156, 214, 220, 179, 125, 87, 63, 37, 17, 31, 81, 138, 170, 180, 186, 191, 196, 197, 171, 103, 38, 36, 92, 168, 218, 215, 170, 120, 87, 63, 33, 15, 38, 92, 143, 169, 181, 187, 191, 197, 198, 163, 88, 35, 46, 107, 180, 220, 208, 160, 114, 84, 57, 25, 14, 44, 102, 148, 172, 184, 189, 191, 200, 199, 150, 76, 35, 55, 120, 189, 221, 201, 154, 112, 84, 51, 20, 16, 54, 110, 151, 173, 185, 188, 193, 207, 197, 138, 68, 39, 67, 134, 197, 219, 193, 146, 111, 81, 46, 17, 21, 64, 116, 153, 174, 184, 187, 198, 213, 191, 126, 61, 42, 79, 148, 205, 218, 185, 142, 109, 77, 39, 13, 26, 72, 120, 154, 176, 184, 187, 205, 216, 183, 115, 58, 48, 91, 159, 210, 211, 175, 136, 105, 71, 30, 10, 31, 78, 123, 156, 176, 180, 188, 210, 213, 170, 102, 52, 53, 103, 171, 214, 206, 170, 136, 106, 68, 27, 13, 40, 86, 128, 161, 177, 179, 193, 215, 208, 158, 91, 50, 61, 116, 182, 214, 200, 166, 135, 103, 59, 21, 15, 47, 90, 131, 162, 172, 176, 197, 216, 200, 145, 81, 50, 69, 128, 190, 213, 195, 162, 133, 97, 52, 18, 21, 53, 93, 134, 161, 168, 177, 201, 214, 190, 130, 72, 48, 77, 141, 196, 212, 191, 161, 133, 93, 45, 17, 26, 57, 98, 139, 160, 165, 181, 205, 212, 179, 118, 65, 50, 87, 152, 201, 207, 185, 159, 130, 86, 39, 19, 31, 62, 103, 140, 155, 163, 183, 206, 206, 166, 105, 56, 52, 97, 162, 202, 202, 182, 158, 126, 78, 35, 22, 36, 68, 111, 142, 154, 166, 188, 210, 202, 157, 95, 52, 57, 108, 168, 200, 197, 179, 158, 122, 71, 34, 25, 40, 75, 117, 142, 152, 167, 193, 211, 195, 145, 84, 49, 63, 118, 174, 198, 193, 178, 157, 115, 65, 34, 27, 45, 84, 121, 142, 153, 172, 199, 211, 188, 133, 74, 46, 70, 126, 176, 194, 188, 177, 152, 107, 61, 35, 31, 54, 94, 126, 143, 155, 179, 205, 211, 181, 123, 67, 49, 80, 136, 179, 190, 186, 175, 145, 98, 57, 33, 33, 61, 100, 129, 143, 158, 183, 208, 208, 172, 111, 60, 52, 90, 145, 179, 188, 186, 174, 139, 93, 54, 32, 38, 68, 107, 133, 147, 165, 193, 214, 207, 164, 101, 56, 57, 100, 151, 179, 187, 188, 170, 130, 86, 48, 30, 41, 74, 111, 133, 147, 169, 198, 215, 202, 153, 92, 54, 64, 110, 155, 178, 188, 188, 165, 125, 80, 45, 32, 47, 82, 115, 134, 149, 175, 203, 217, 198, 145, 86, 56, 75, 121, 160, 180, 191, 186, 160, 119, 74, 41, 33, 52, 87, 117, 134, 153, 181, 209, 219, 192, 136, 79, 58, 84, 129, 161, 181, 192, 183, 154, 112, 69, 38, 33, 55, 90, 116, 132, 154, 184, 212, 216, 183, 124, 72, 62, 95, 135, 164, 186, 194, 181, 150, 106, 62, 35, 36, 63, 95, 117, 134, 157, 189, 215, 212, 173, 113, 69, 70, 104, 139, 168, 189, 194, 178, 145, 100, 58, 34, 39, 67, 94, 113, 131, 158, 192, 214, 206, 162, 103, 66, 77, 110, 143, 172, 191, 194, 176, 139, 93, 53, 33, 44, 71, 95, 113, 133, 163, 196, 215, 200, 151, 93, 68, 84, 116, 149, 178, 195, 193, 173, 133, 87, 48, 35, 49, 74, 95, 112, 133, 165, 199, 213, 192, 137, 84, 68, 87, 118, 151, 179, 194, 193, 169, 129, 81, 45, 36, 53, 77, 96, 112, 136, 171, 202, 210, 182, 124, 79, 72, 92, 123, 156, 182, 198, 193, 167, 125, 77, 44, 41, 58, 79, 96, 113, 141, 177, 206, 210, 173, 115, 77, 74, 94, 125, 157, 183, 197, 190, 162, 118, 71, 44, 45, 63, 82, 97, 116, 146, 181, 209, 204, 160, 105, 76, 77, 98, 129, 160, 185, 195, 185, 155, 109, 66, 45, 50, 67, 85, 99, 121, 152, 188, 212, 198, 149, 99, 75, 79, 102, 132, 164, 187, 195, 183, 150, 104, 64, 48, 54, 71, 87, 103, 126, 159, 196, 215, 192, 139, 94, 74, 81, 105, 136, 167, 188, 194, 179, 143, 96, 60, 49, 58, 74, 88, 105, 130, 165, 204, 216, 184, 133, 92, 77, 86, 109, 139, 168, 188, 192, 175, 135, 89, 58, 51, 62, 76, 90, 108, 135, 173, 210, 212, 176, 127, 91, 80, 90, 114, 144, 172, 189, 191, 169, 126, 82, 56, 54, 65, 79, 94, 113, 142, 184, 215, 207, 168, 121, 90, 82, 94, 120, 150, 176, 192, 190, 163, 118, 76, 55, 55, 65, 78, 94, 114, 148, 192, 216, 202, 160, 116, 89, 84, 98, 124, 153, 177, 193, 187, 156, 111, 73, 56, 57, 67, 80, 95, 116, 156, 199, 215, 196, 154, 113, 90, 88, 103, 129, 156, 181, 194, 183, 149, 104, 70, 56, 57, 65, 79, 92, 119, 163, 203, 213, 188, 146, 109, 90, 91, 108, 134, 162, 186, 196, 181, 143, 99, 69, 58, 58, 68, 78, 92, 123, 170, 205, 208, 180, 138, 105, 90, 94, 112, 137, 165, 188, 195, 175, 135, 93, 66, 56, 59, 68, 75, 91, 128, 175, 205, 203, 171, 132, 102, 89, 96, 115, 141, 170, 193, 196, 173, 130, 91, 67, 58, 62, 69, 75, 95, 136, 180, 205, 196, 163, 126, 99, 89, 98, 118, 144, 174, 196, 195, 167, 125, 89, 66, 60, 64, 67, 73, 98, 141, 184, 203, 188, 155, 119, 95, 89, 99, 119, 148, 179, 199, 193, 161, 121, 87, 66, 63, 66, 66, 75, 104, 148, 188, 199, 180, 147, 113, 92, 89, 101, 122, 152, 182, 199, 189, 155, 117, 85, 68, 67, 66, 66, 78, 110, 156, 191, 196, 175, 141, 108, 91, 91, 102, 125, 157, 188, 201, 185, 151, 113, 83, 70, 69, 66, 67, 83, 120, 165, 194, 193, 169, 135, 105, 91, 91, 103, 128, 160, 190, 198, 179, 144, 107, 80, 71, 68, 64, 66, 87, 128, 172, 195, 190, 164, 129, 102, 90, 91, 105, 131, 166, 194, 196, 176, 141, 103, 81, 74, 69, 64, 68, 93, 137, 178, 196, 187, 158, 124, 101, 90, 93, 108, 135, 171, 195, 193, 171, 134, 99, 82, 75, 69, 63, 70, 101, 147, 184, 197, 184, 153, 121, 100, 91, 95, 111, 141, 176, 195, 190, 164, 126, 95, 81, 74, 67, 62, 73, 109, 154, 187, 195, 178, 148, 118, 99, 93, 97, 115, 148, 180, 195, 188, 158, 120, 93, 81, 75, 66, 61, 77, 117, 161, 190, 195, 175, 145, 117, 100, 94, 98, 120, 155, 183, 196, 184, 151, 115, 92, 80, 72, 62, 59, 82, 124, 166, 191, 190, 169, 140, 114, 100, 94, 100, 126, 160, 187, 197, 180, 146, 112, 92, 81, 71, 58, 60, 88, 130, 170, 191, 187, 164, 135, 113, 100, 94, 103, 131, 164, 189, 195, 174, 140, 109, 91, 82, 68, 55, 62, 94, 137, 175, 191, 184, 160, 132, 113, 100, 94, 108, 137, 169, 192, 193, 169, 135, 108, 93, 82, 64, 53, 64, 98, 143, 177, 189, 179, 153, 128, 110, 96, 94, 111, 141, 173, 194, 189, 163, 131, 106, 93, 79, 60, 52, 67, 104, 147, 178, 187, 173, 147, 126, 108, 95, 97, 115, 145, 178, 195, 186, 159, 127, 106, 93, 76, 57, 53, 72, 111, 152, 179, 185, 167, 143, 123, 105, 94, 99, 119, 151, 183, 196, 184, 155, 125, 106, 92, 72, 55, 54, 77, 117, 156, 181, 181, 161, 140, 119, 100, 92, 99, 122, 157, 187, 196, 181, 150, 123, 107, 90, 69, 52, 55, 82, 122, 160, 182, 176, 157, 136, 114, 97, 91, 100, 126, 162, 189, 195, 176, 146, 123, 106, 88, 66, 52, 59, 89, 128, 166, 181, 172, 153, 132, 110, 95, 91, 102, 131, 167, 192, 194, 171, 143, 122, 105, 85, 63, 52, 64, 95, 136, 171, 180, 169, 151, 128, 108, 94, 90, 105, 136, 171, 193, 191, 167, 142, 123, 105, 83, 60, 54, 69, 102, 145, 173, 177, 166, 148, 125, 106, 92, 90, 108, 140, 174, 193, 185, 161, 139, 121, 103, 79, 58, 56, 74, 110, 151, 174, 176, 165, 146, 124, 105, 92, 93, 113, 146, 179, 192, 181, 158, 138, 121, 101, 75, 58, 58, 79, 119, 157, 176, 176, 164, 143, 122, 103, 91, 95, 117, 151, 181, 189, 176, 154, 136, 119, 96, 71, 57, 60, 85, 127, 161, 176, 176, 162, 142, 121, 101, 91, 97, 121, 157, 184, 187, 172, 151, 135, 116, 91, 68, 56, 61, 92, 133, 163, 176, 172, 158, 139, 117, 99, 91, 99, 126, 162, 185, 185, 168, 149, 134, 114, 88, 66, 55, 65, 100, 139, 167, 177, 171, 157, 137, 115, 98, 92, 103, 134, 168, 186, 181, 164, 148, 132, 109, 84, 62, 52, 69, 105, 142, 168, 176, 169, 154, 133, 112, 96, 91, 106, 139, 171, 186, 178, 162, 148, 130, 106, 81, 59, 54, 75, 111, 147, 169, 174, 167, 152, 130, 110, 95, 92, 112, 145, 174, 183, 174, 160, 147, 127, 103, 77, 55, 55, 79, 115, 149, 168, 172, 165, 147, 126, 107, 93, 94, 117, 151, 177, 181, 171, 160, 145, 124, 100, 72, 53, 58, 84, 120, 152, 168, 170, 162, 143, 123, 103, 90, 95, 121, 156, 178, 179, 171, 160, 143, 123, 96, 67, 52, 61, 89, 125, 153, 167, 168, 158, 140, 120, 99, 89, 98, 128, 161, 178, 178, 171, 159, 142, 121, 93, 64, 54, 65, 95, 130, 154, 166, 165, 153, 136, 116, 96, 88, 102, 134, 165, 177, 177, 170, 157, 141, 118, 87, 62, 54, 69, 101, 133, 155, 165, 162, 150, 132, 111, 93, 88, 105, 139, 166, 176, 177, 169, 157, 141, 115, 83, 61, 56, 74, 106, 136, 157, 165, 160, 148, 129, 108, 90, 88, 111, 145, 167, 177, 177, 168, 157, 140, 111, 80, 60, 58, 80, 112, 140, 159, 164, 158, 145, 126, 105, 87, 90, 117, 149, 168, 177, 176, 168, 157, 136, 106, 77, 58, 62, 86, 116, 144, 160, 163, 157, 143, 123, 100, 84, 93, 122, 151, 169, 176, 173, 167, 156, 133, 103, 74, 59, 67, 92, 121, 147, 161, 164, 157, 142, 121, 96, 84, 98, 127, 153, 170, 175, 173, 168, 154, 130, 99, 71, 60, 71, 96, 126, 149, 161, 163, 154, 140, 118, 93, 86, 104, 131, 156, 171, 173, 172, 167, 152, 127, 95, 68, 62, 76, 102, 131, 152, 163, 163, 154, 139, 113, 89, 89, 109, 135, 159, 170, 173, 173, 166, 150, 122, 89, 67, 64, 79, 107, 135, 154, 164, 161, 153, 136, 107, 87, 91, 112, 139, 161, 169, 173, 172, 164, 146, 116, 83, 65, 65, 83, 111, 138, 156, 163, 161, 153, 131, 102, 87, 94, 116, 143, 161, 168, 173, 171, 163, 143, 111, 80, 64, 67, 87, 115, 141, 158, 162, 161, 152, 126, 99, 88, 97, 121, 146, 161, 169, 173, 170, 161, 138, 105, 76, 62, 68, 90, 118, 143, 157, 161, 162, 148, 120, 96, 88, 100, 125, 148, 161, 169, 172, 171, 160, 133, 100, 73, 62, 71, 93, 122, 145, 156, 162, 161, 143, 114, 93, 89, 104, 129, 148, 161, 169, 172, 171, 157, 128, 96, 70, 63, 73, 97, 126, 146, 155, 163, 160, 137, 110, 91, 91, 110, 132, 150, 163, 170, 174, 171, 154, 124, 91, 69, 64, 75, 100, 128, 145, 156, 164, 155, 131, 105, 89, 93, 113, 134, 152, 163, 170, 175, 170, 150, 119, 87, 68, 65, 79, 106, 130, 144, 157, 163, 151, 127, 100, 88, 97, 116, 137, 154, 164, 172, 176, 169, 147, 114, 84, 67, 65, 82, 110, 130, 144, 159, 161, 147, 121, 95, 88, 99, 119, 140, 155, 165, 174, 176, 167, 143, 110, 83, 68, 68, 89, 115, 132, 148, 161, 160, 143, 115, 92, 89, 101, 122, 143, 156, 167, 175, 177, 165, 138, 105, 80, 66, 71, 95, 117, 134, 151, 162, 159, 139, 110, 91, 90, 104, 125, 143, 157, 169, 177, 178, 163, 133, 102, 78, 66, 77, 100, 119, 137, 154, 163, 158, 134, 106, 91, 92, 108, 128, 143, 157, 169, 178, 177, 159, 130, 100, 76, 68, 83, 103, 122, 141, 157, 165, 156, 129, 104, 91, 95, 112, 130, 145, 159, 171, 180, 175, 154, 125, 96, 72, 71, 87, 105, 125, 143, 159, 166, 152, 125, 101, 91, 97, 114, 131, 146, 160, 173, 181, 172, 150, 122, 91, 72, 75, 90, 109, 129, 146, 163, 166, 148, 121, 99, 93, 102, 118, 134, 148, 162, 176, 181, 169, 148, 118, 87, 73, 77, 92, 112, 130, 149, 166, 164, 144, 117, 97, 93, 104, 119, 135, 148, 163, 177, 178, 166, 145, 113, 84, 74, 79, 94, 113, 131, 152, 166, 161, 139, 113, 96, 96, 106, 121, 136, 149, 165, 178, 177, 165, 141, 107, 83, 75, 81, 98, 115, 134, 156, 166, 157, 134, 109, 95, 97, 108, 123, 136, 149, 167, 177, 175, 163, 135, 102, 81, 75, 84, 100, 115, 137, 158, 164, 153, 129, 105, 95, 98, 111, 125, 136, 153, 170, 177, 175, 160, 129, 99, 80, 76, 87, 100, 117, 140, 159, 163, 149, 123, 102, 94, 99, 113, 125, 137, 156, 171, 176, 175, 155, 124, 96, 78, 78, 89, 101, 120, 143, 160, 162, 144, 118, 100, 93, 101, 115, 125, 141, 160, 171, 178, 173, 150, 120, 93, 78, 81, 90, 103, 123, 146, 161, 159, 139, 115, 97, 94, 104, 115, 126, 144, 161, 173, 179, 170, 145, 115, 89, 79, 83, 91, 105, 126, 148, 161, 155, 133, 110, 94, 95, 105, 114, 128, 146, 162, 175, 180, 167, 142, 111, 87, 81, 84, 93, 109, 130, 153, 162, 151, 129, 106, 93, 98, 106, 115, 131, 148, 164, 178, 180, 165, 139, 107, 88, 83, 85, 95, 112, 135, 156, 161, 148, 126, 102, 94, 99, 105, 116, 132, 148, 166, 179, 178, 163, 134, 105, 89, 84, 87, 97, 115, 140, 159, 160, 146, 121, 100, 95, 98, 104, 118, 133, 150, 169, 180, 178, 160, 129, 103, 89, 85, 89, 100, 120, 145, 160, 159, 144, 117, 100, 97, 98, 106, 120, 134, 154, 172, 181, 178, 156, 125, 102, 89, 86, 91, 102, 125, 149, 161, 159, 139, 113, 101, 97, 99, 109, 121, 136, 157, 173, 182, 176, 151, 121, 100, 89, 87, 91, 105, 131, 152, 163, 158, 134, 112, 102, 97, 101, 111, 122, 140, 159, 175, 182, 172, 146, 118, 98, 89, 87, 92, 111, 135, 154, 165, 154, 129, 111, 101, 98, 103, 111, 124, 143, 161, 176, 182, 168, 141, 115, 97, 90, 87, 94, 115, 137, 158, 165, 149, 126, 110, 100, 99, 105, 113, 128, 146, 164, 179, 181, 164, 138, 112, 97, 88, 85, 97, 116, 139, 161, 162, 144, 125, 109, 100, 101, 105, 114, 129, 147, 166, 180, 178, 159, 132, 109, 95, 85, 85, 99, 118, 143, 162, 158, 140, 122, 105, 100, 101, 105, 116, 131, 149, 169, 181, 176, 156, 128, 109, 95, 85, 88, 101, 121, 148, 162, 154, 138, 119, 105, 101, 101, 106, 118, 133, 153, 172, 181, 174, 150, 125, 107, 92, 85, 90, 102, 125, 151, 159, 151, 134, 114, 103, 100, 99, 107, 119, 135, 155, 173, 181, 170, 146, 123, 105, 90, 86, 91, 104, 131, 
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody); thisNote++) {
    tone(8, melody[thisNote],100);
    delay(130);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
