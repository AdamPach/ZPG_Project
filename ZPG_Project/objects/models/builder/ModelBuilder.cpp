#include "ModelBuilder.h"
#include "../../../defaults.h"
#include "../abstraction/PositionModel.h"
#include "../abstraction/TriangleNormalModel.h"
#include "../abstraction/TriangleNormalTexturedModel.h"

#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>

#include <vector>

BuildableModelBuilder* ModelBuilder::FromFile(std::string fileName)
{
	this->fileName = fileName;

	this->buildType = ModelBuilder::File;

	return this;
}

PointModelBuilder* ModelBuilder::FromPoints(float* points, int length)
{
	this->points = points;
	this->length = length;

	this->buildType = ModelBuilder::Points;

	return this;
}

PointModelBuilder* ModelBuilder::HasPosition()
{
	hasPosition = true;

	return this;
}

PointModelBuilder* ModelBuilder::HasNormals()
{
	hasNormals = true;

	return this;
}

PointModelBuilder* ModelBuilder::HasTextureCoordinates()
{
	hasTextureCoordinates = true;

	return this;
}

StartModelBuilder* ModelBuilder::Create()
{
	return new ModelBuilder();
}

ModelBuilder::ModelBuilder()
{
	this->points = nullptr;
	this->length = 0;

	this->hasPosition = false;
	this->hasNormals = false;
	this->hasTextureCoordinates = false;

	this->buildType = ModelBuilder::None;

	this->fileName = "";
}

void ModelBuilder::LoadPointsFromFile()
{
	Assimp::Importer importer;

	unsigned int importOptions = aiProcess_Triangulate
		| aiProcess_OptimizeMeshes     
		| aiProcess_JoinIdenticalVertices
		| aiProcess_CalcTangentSpace;

	std::string fName = MODELS_PATH;
	fName.append(fileName);

	const aiScene* scene = importer.ReadFile(fName, importOptions);

	if (scene == nullptr)
	{
		std::cerr << "Error loading model from file: " << fName << std::endl;
		exit(1);
	}

	aiMesh* mesh = scene->mMeshes[0];

	int vertexSize = 0;

	if (mesh->HasPositions())
	{
		vertexSize += 3;
		hasPosition = true;
	}

	if (mesh->HasNormals())
	{
		vertexSize += 3;
		hasNormals = true;
	}

	if (mesh->HasTextureCoords(0))
	{
		vertexSize += 2;
		hasTextureCoordinates = true;
	}
	/*
	points = new float[mesh->mNumVertices * vertexSize];
	length = mesh->mNumVertices * vertexSize * sizeof(float);

	for (unsigned int j = 0; j < mesh->mNumVertices; j++)
	{
		if (hasPosition)
		{
			points[j * vertexSize] = mesh->mVertices[mesh->mFaces].x;
			points[j * vertexSize + 1] = mesh->mVertices[j].y;
			points[j * vertexSize + 2] = mesh->mVertices[j].z;
		}
		if (hasNormals)
		{
			points[j * vertexSize + 3] = mesh->mNormals[j].x;
			points[j * vertexSize + 4] = mesh->mNormals[j].y;
			points[j * vertexSize + 5] = mesh->mNormals[j].z;
		}
		if (hasTextureCoordinates)
		{
			points[j * vertexSize + 6] = mesh->mTextureCoords[0][j].x;
			points[j * vertexSize + 7] = mesh->mTextureCoords[0][j].y;
		}
	}

	*/

	std::vector<float> vertices;

	for (int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; j++)
		{
			aiVector3D vertex = mesh->mVertices[face.mIndices[j]];
			vertices.push_back(vertex.x);
			vertices.push_back(vertex.y);
			vertices.push_back(vertex.z);
			if (hasNormals)
			{
				aiVector3D normal = mesh->mNormals[face.mIndices[j]];
				vertices.push_back(normal.x);
				vertices.push_back(normal.y);
				vertices.push_back(normal.z);
			}
			if (hasTextureCoordinates)
			{
				aiVector3D texture = mesh->mTextureCoords[0][face.mIndices[j]];
				vertices.push_back(texture.x);
				vertices.push_back(texture.y);
			}
		}
	}

	points = new float[vertices.size()];
	length = vertices.size() * sizeof(float);

	for (int i = 0; i < vertices.size(); i++)
	{
		points[i] = vertices[i];
	}
}

Model* ModelBuilder::Build()
{
	if (buildType == ModelBuilder::File)
	{
		LoadPointsFromFile();
	}

	Model* model;

	if (hasPosition && hasNormals && hasTextureCoordinates)
	{
		model = new TriangleNormalTexturedModel(points, length);
	}
	else if (hasPosition && hasNormals)
	{
		model = new TriangleNormalModel(points, length);
	}
	else
	{
		model = new PositionModel(points, length);
	}

	if (buildType == ModelBuilder::File)
	{
		delete[] points;
	}

	this->length = 0;

	this->hasPosition = false;
	this->hasNormals = false;
	this->hasTextureCoordinates = false;

	this->buildType = ModelBuilder::None;

	this->fileName = "";

	return model;
}
