#include "KDTree.h"
#include <math.h>

KDNode::KDNode(double lat, double lon, const char *desc) {
	left = NULL;
	right = NULL;
	description = desc;
	latitude = lat;
	longitude = lon;
}

KDNode::~KDNode() {
}

double KDNode::distance(double lat, double lon) {
	double param = M_PI / 180.0; // required for conversion from degrees to radians
	double rad = 3956.0;  // radius of earth in miles
	double d_lat = (lat - latitude) * param;
	double d_lon = (lon - longitude) * param;
	double dist = sin(d_lat/2) * sin(d_lat/2) + cos(latitude*param) * cos(lat*param) * sin(d_lon/2) * sin(d_lon/2);
	dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
	return rad * dist;
}

KDTree::KDTree() {
	root = NULL;
	size = 0;
}

KDTree::~KDTree() {
	destroy(root);	
}

void destroyHelper(KDNode *p) {
	if (!p)
		return;
	destroyHelper(p->left);
	destroyHelper(p->right);
	delete p;

}

void KDTree::destroy(KDNode *p) {
	size = 0;
	destroyHelper(root);
	root = NULL;
}


void KDTree::insert(double lat, double lon, const char *desc) {
	// TODO
}

unsigned int KDTree::printNeighbors(double lat, double lon, double rad, const char *filter) {
	// TODO
	return -1;
}

unsigned int KDTree::getSize() {
	return size;
}
