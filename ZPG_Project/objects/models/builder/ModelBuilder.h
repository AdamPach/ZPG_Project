#pragma once

#include <iostream>

#include "../abstraction/Model.h"

class BuildableModelBuilder 
{
public:
	virtual Model* Build() = 0;
};

class PointModelBuilder : public BuildableModelBuilder
{
public:
	virtual PointModelBuilder* HasPosition() = 0;
	virtual PointModelBuilder* HasNormals() = 0;
	virtual PointModelBuilder* HasTextureCoordinates() = 0;
};

class StartModelBuilder
{
public:
	virtual BuildableModelBuilder* FromFile(std::string fileName) = 0;
	virtual PointModelBuilder* FromPoints(float* points, int length) = 0;
};

class ModelBuilder : public StartModelBuilder, public PointModelBuilder
{
public:
	BuildableModelBuilder* FromFile(std::string fileName) override;
	PointModelBuilder* FromPoints(float* points, int length) override;

	PointModelBuilder* HasPosition() override;
	PointModelBuilder* HasNormals() override;
	PointModelBuilder* HasTextureCoordinates() override;

	Model* Build() override;

	static StartModelBuilder* Create();
private:
	ModelBuilder();
	void LoadPointsFromFile();

	enum BuildType
	{
		None,
		File,
		Points
	};

	float* points;
	int length;

	bool hasPosition;
	bool hasNormals;
	bool hasTextureCoordinates;

	std::string fileName;

	BuildType buildType;
};