// -*- c++ -*-
// Copyright 2009 Isis Innovation Limited

/********************************************************************

A set of utility functions
Author: Robert Castle, 2009, bob@robots.ox.ac.uk

********************************************************************/

#include <string>
#include <iostream>
#include <iterator>
#include <vector>

#include <opencv2/core/core.hpp>
//#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

//#include <opencv2/core/types.hpp>

#include <pcl/io/pcd_io.h>

#ifndef __VITAM_UTILS__
#define __VITAM_UTILS__

#endif


#ifndef UTILS_H_
#define UTILS_H_
// Draw a text with the question point
void drawQuestion(cv::Mat image, cv::Point3f point, cv::Scalar color);

// Draw a text with the number of entered points
void drawText(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the number of entered points
void drawText2(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the frame ratio
void drawFPS(cv::Mat image, double fps, cv::Scalar color);

// Draw a text with the frame ratio
void drawConfidence(cv::Mat image, double confidence, cv::Scalar color);

// Draw a text with the number of entered points
void drawCounter(cv::Mat image, int n, int n_max, cv::Scalar color);

// Draw the points and the coordinates
void drawPoints(cv::Mat image, std::vector<cv::Point2f> &list_points_2d, std::vector<cv::Point3f> &list_points_3d, cv::Scalar color);

// Draw only the 2D points
void draw2DPoints(cv::Mat image, std::vector<cv::Point2f> &list_points, cv::Scalar color);

void drawFixation(cv::Mat image, cv::Point2f point);

// Draw an arrow into the image
void drawArrow(cv::Mat image, cv::Point2i p, cv::Point2i q, cv::Scalar color, int arrowMagnitude = 9, int thickness = 1, int line_type = 8, int shift = 0);

// Draw the 3D coordinate axes
void draw3DCoordinateAxes(cv::Mat image, const std::vector<cv::Point2f> &list_points2d);

// Draw the object mesh
//void drawObjectMesh(cv::Mat image, const Mesh *mesh, PnPProblem *pnpProblem, cv::Scalar color);

// Computes the norm of the translation error
double get_translation_error(const cv::Mat &t_true, const cv::Mat &t);

// Computes the norm of the rotation error
double get_rotation_error(const cv::Mat &R_true, const cv::Mat &R);

// Converts a given Rotation Matrix to Euler angles
cv::Mat rot2euler(const cv::Mat & rotationMatrix);

// Converts a given Euler angles to Rotation Matrix
cv::Mat euler2rot(const cv::Mat & euler);

// Converts a given string to an integer
int StringToInt(const std::string &Text);

// Converts a given string to a float
float StringToFloat(const std::string &Text);

// Converts a given float to a string
std::string FloatToString(float Number);

// Converts a given integer to a string
std::string IntToString(int Number);

cv::Mat RT_to_Mat(cv::Mat rotation, cv::Mat translation);

cv::Mat Point_to_Mat(cv::Point3f point);

cv::Point3f Mat_to_Point(cv::Mat point);

pcl::PointXYZ Point_to_Cloud(cv::Point3f point);

unsigned long StringToLong(const std::string &Text);

void fillMeasurements(cv::Mat &measurements,
	const cv::Mat &translation_measured, const cv::Mat &rotation_measured);

struct EyeTracker_Fixations {
	int start;
	int end;
	int duration;
	cv::Point2f fixation;
	cv::Point3f fixation3D;
};

struct EyeTracker_PoR {
	unsigned int frame;
	cv::Point2f PoR;
	bool is_fixation;
	bool is_saccade;
	float speed;
};



#endif /* UTILS_H_ */