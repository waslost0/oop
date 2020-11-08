#include "pch.h"
#include "../GeometricShapes/CPoint.cpp"
#include "../GeometricShapes/CCircle.cpp"
#include "../GeometricShapes/CLineSegment.cpp"
#include "../GeometricShapes/CRectangle.cpp"
#include "../GeometricShapes/CShapeController.cpp"
#include "../GeometricShapes/CTriangle.cpp"
#include "../GeometricShapes/Const.h"



TEST(Shape, CPoint) {
	CPoint point(15.15, 19.85);
	EXPECT_EQ(point.GetX(), 15.15);
	EXPECT_EQ(point.GetY(), 19.85);
}

TEST(Shape, CRectangle) {
	CPoint leftTop(535.0, 300.0);
	double width = 545.0, height = 400.0;
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

	EXPECT_EQ(rectangle.GetArea(), 218000.0);
	EXPECT_EQ(rectangle.GetPerimeter(), 1890.0);
	EXPECT_EQ(rectangle.GetWidth(), width);
	EXPECT_EQ(rectangle.GetHeight(), height);
	EXPECT_EQ(rectangle.GetLeftTop().GetX(), leftTop.GetX());
	EXPECT_EQ(rectangle.GetLeftTop().GetY(), leftTop.GetY());

	EXPECT_EQ(rectangle.GetRightBottom().GetX(), 1080.0);
	EXPECT_EQ(rectangle.GetRightBottom().GetY(), 700.0);

	std::stringstream issOut;
	std::stringstream issOutCheck("rectangle\nArea 218000\nPerimeter 1890\nLeft top 535 300\nRight bottom 1080 700\nWidth 545\nHeight 400\nOutline color ffd700\nFill color ff0000\n");

	rectangle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(rectangle.GetFillColor(), "ff0000");
	EXPECT_EQ(rectangle.GetOutlineColor(), "ffd700");
}
TEST(Shape, CRectangle_nondegenerate) {
	CPoint leftTop(535.0, 300.0);
	double width = 545.0, height = 400.0;
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

	EXPECT_EQ(rectangle.GetArea(), 218000.0);
	EXPECT_EQ(rectangle.GetPerimeter(), 1890.0);
	EXPECT_EQ(rectangle.GetWidth(), width);
	EXPECT_EQ(rectangle.GetHeight(), height);
	EXPECT_EQ(rectangle.GetLeftTop().GetX(), leftTop.GetX());
	EXPECT_EQ(rectangle.GetLeftTop().GetY(), leftTop.GetY());

	EXPECT_EQ(rectangle.GetRightBottom().GetX(), 1080.0);
	EXPECT_EQ(rectangle.GetRightBottom().GetY(), 700.0);

	std::stringstream issOut;
	std::stringstream issOutCheck("rectangle\nArea 218000\nPerimeter 1890\nLeft top 535 300\nRight bottom 1080 700\nWidth 545\nHeight 400\nOutline color ffd700\nFill color ff0000\n");

	rectangle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(rectangle.GetFillColor(), "ff0000");
	EXPECT_EQ(rectangle.GetOutlineColor(), "ffd700");
}

TEST(Shape, CTriangle) {
	CPoint vertex1(0.0, 0.0);
	CPoint vertex2(0.0, 3.0);
	CPoint vertex3(4.0, 3.0);
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

	EXPECT_EQ(triangle.GetArea(), 6.0);
	EXPECT_EQ(triangle.GetPerimeter(), 12.0);

	EXPECT_EQ(triangle.GetVertex1().GetX(), vertex1.GetX());
	EXPECT_EQ(triangle.GetVertex1().GetY(), vertex1.GetY());

	EXPECT_EQ(triangle.GetVertex2().GetX(), vertex2.GetX());
	EXPECT_EQ(triangle.GetVertex2().GetY(), vertex2.GetY());

	EXPECT_EQ(triangle.GetVertex3().GetX(), vertex3.GetX());
	EXPECT_EQ(triangle.GetVertex3().GetY(), vertex3.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("triangle\nArea 6\nPerimeter 12\nVertex1 0 0\nVertex2 0 3\nVertex3 4 3\nOutline color ffd700\nFill color ff0000\n");

	triangle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(triangle.GetFillColor(), "ff0000");
	EXPECT_EQ(triangle.GetOutlineColor(), "ffd700");
}

TEST(Shape, CTriangle_nondegenerate) {
	CPoint vertex1(0.0, 0.0);
	CPoint vertex2(3.0, 0.0);
	CPoint vertex3(8.0, 0.0);
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

	EXPECT_EQ(triangle.GetArea(), 0.0);
	EXPECT_EQ(triangle.GetPerimeter(), 16.0);

	EXPECT_EQ(triangle.GetVertex1().GetX(), vertex1.GetX());
	EXPECT_EQ(triangle.GetVertex1().GetY(), vertex1.GetY());

	EXPECT_EQ(triangle.GetVertex2().GetX(), vertex2.GetX());
	EXPECT_EQ(triangle.GetVertex2().GetY(), vertex2.GetY());

	EXPECT_EQ(triangle.GetVertex3().GetX(), vertex3.GetX());
	EXPECT_EQ(triangle.GetVertex3().GetY(), vertex3.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("triangle\nArea 0\nPerimeter 16\nVertex1 0 0\nVertex2 3 0\nVertex3 8 0\nOutline color ffd700\nFill color ff0000\n");

	triangle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(triangle.GetFillColor(), "ff0000");
	EXPECT_EQ(triangle.GetOutlineColor(), "ffd700");
}

TEST(Shape, CCircle) {

	CPoint center(0.0, 0.0);
	double radius = 3;
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CCircle circle(center, radius, outlineColor, fillColor);

	EXPECT_EQ(circle.GetArea(), M_PI * 9);
	EXPECT_EQ(circle.GetPerimeter(), M_PI * 6);
	EXPECT_EQ(circle.GetRadius(), radius);
	EXPECT_EQ(circle.GetCenter().GetX(), center.GetX());
	EXPECT_EQ(circle.GetCenter().GetY(), center.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("circle\nArea 28.2743\nPerimeter 18.8496\nCenter 0 0\nRadius 3\nOutline color ffd700\nFill color ff0000\n");

	circle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(circle.GetFillColor(), "ff0000");
	EXPECT_EQ(circle.GetOutlineColor(), "ffd700");
}

TEST(Shape, CCircle_nondegenerate) {

	CPoint center(1.0, 1.0);
	double radius = 0.0;
	std::string outlineColor = "ffd700", fillColor = "ff0000";
	CCircle circle(center, radius, outlineColor, fillColor);

	EXPECT_EQ(circle.GetArea(), 0.0);
	EXPECT_EQ(circle.GetPerimeter(), 0.0);
	EXPECT_EQ(circle.GetRadius(), radius);
	EXPECT_EQ(circle.GetCenter().GetX(), center.GetX());
	EXPECT_EQ(circle.GetCenter().GetY(), center.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("circle\nArea 0\nPerimeter 0\nCenter 1 1\nRadius 0\nOutline color ffd700\nFill color ff0000\n");

	circle.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(circle.GetFillColor(), "ff0000");
	EXPECT_EQ(circle.GetOutlineColor(), "ffd700");
}

TEST(Shape, CLineSegment) {

	CPoint startPoint(0.0, 15.0);
	CPoint endPoint(15.0, 7.0);
	std::string outlineColor = "ffd700";
	CLineSegment line(startPoint, endPoint, outlineColor);

	EXPECT_EQ(line.GetArea(), 0.0);
	EXPECT_EQ(line.GetPerimeter(), 17.0);
	EXPECT_EQ(line.GetStartPoint().GetX(), startPoint.GetX());
	EXPECT_EQ(line.GetStartPoint().GetY(), startPoint.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("line\nArea 0\nPerimeter 17\nStart point 0 15\nEnd point 15 7\nOutline color ffd700\n");

	line.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(line.GetEndPoint().GetX(), endPoint.GetX());
	EXPECT_EQ(line.GetEndPoint().GetY(), endPoint.GetY());

	EXPECT_EQ(line.GetOutlineColor(), "ffd700");
}

TEST(Shape, CLineSegment_nondegenerat) {

	CPoint startPoint(2.0, 2.0);
	CPoint endPoint(2.0, 2.0);
	std::string outlineColor = "ffd471";
	CLineSegment line(startPoint, endPoint, outlineColor);

	EXPECT_EQ(line.GetArea(), 0.0);
	EXPECT_EQ(line.GetPerimeter(), 0.0);
	EXPECT_EQ(line.GetStartPoint().GetX(), startPoint.GetX());
	EXPECT_EQ(line.GetStartPoint().GetY(), startPoint.GetY());

	std::stringstream issOut;
	std::stringstream issOutCheck("line\nArea 0\nPerimeter 0\nStart point 2 2\nEnd point 2 2\nOutline color ffd471\n");

	line.PrintInfo(issOut);
	EXPECT_EQ(issOut.str(), issOutCheck.str());

	EXPECT_EQ(line.GetEndPoint().GetX(), endPoint.GetX());
	EXPECT_EQ(line.GetEndPoint().GetY(), endPoint.GetY());

	EXPECT_EQ(line.GetOutlineColor(), "ffd471");
}

TEST(ShapeController, CRectangle) {

	std::stringstream issIn("rectangle 10.3 20.15 30.7 40.4 ff0000 00ff00");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("rectangle\nArea 1240.28\nPerimeter 142.2\nLeft top 10.3 20.15\nRight bottom 41 60.55\nWidth 30.7\nHeight 40.4\nOutline color ff0000\nFill color 00ff00\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}

TEST(ShapeController, CTriangle) {

	std::stringstream issIn("triangle 0 0 -6 0 -5 8 940c0c ad9e9e");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("triangle\nArea 24\nPerimeter 23.4962\nVertex1 0 0\nVertex2 -6 0\nVertex3 -5 8\nOutline color 940c0c\nFill color ad9e9e\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}

TEST(ShapeController, CCircle) {
	std::stringstream issIn("circle 0 150 69.17 e04f4f 290707");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("circle\nArea 15030.9\nPerimeter 434.608\nCenter 0 150\nRadius 69.17\nOutline color e04f4f\nFill color 290707\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}

TEST(ShapeController, CLineSegment) {
	std::stringstream issIn("line 0 15 88 120 704141");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("line\nArea 0\nPerimeter 137\nStart point 0 15\nEnd point 88 120\nOutline color 704141\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}

TEST(ShapeController, Unknown_figure) {
	std::stringstream issIn("hello 0 15 88 120 704141");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("Unknown figure\nYou have not created a shape\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}

TEST(ShapeController, Empty_input) {
	std::stringstream issIn("");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("You have not created a shape\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}


TEST(ShapeController, PrintShapeInfo) {
	std::stringstream issIn("line 10 14 35 10 c24444\nrectangle 0 0 30 10 300b0b 1f1717\ncircle 46.9 35.1 18.9 249fa6 719407\ntriangle 53 33.9 12 39 40 75.1 0a3304 330404");
	std::stringstream issOut;

	CShapeController shapeController(issIn, issOut);

	shapeController.ProcessingCommand();
	shapeController.PrintShapeInfo();

	std::stringstream issOutCheck("The figure with the maximum area: circle\nArea 1122.21\nPerimeter 118.752\nCenter 46.9 35.1\nRadius 18.9\nOutline color 249fa6\nFill color 719407\n\nThe figure with the minimum perimeter: line\nArea 0\nPerimeter 25.318\nStart point 10 14\nEnd point 35 10\nOutline color c24444\n");

	EXPECT_EQ(issOut.str(), issOutCheck.str());
}
