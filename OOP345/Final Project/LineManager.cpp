// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Apr. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <cassert>
#include <fstream>
#include <thread>
#include <mutex>
#include "Utilities.h"
#include "CustomerOrder.h"
#include "LineManager.h"
#include "Workstation.h"

namespace sdds {
	using namespace std;

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		activeLine.reserve(1024);
		Utilities ut;
		std::ifstream ifs(file);
		
		if (!ifs) {
			std::cout << "unable to open the file" << std::endl;
			exit(-1);
		}
		
		vector<Workstation*>::const_iterator startStaions = stations.begin(); 
		vector<Workstation*>::const_iterator endStations = stations.end();
		
		bool isMore = false;
		string record;
		string stationName;
		size_t indexPos = 0;
		
		auto fn = [&](Workstation* ws)->void {
			if (!ws)
				activeLine.push_back(ws);
			else if (stationName == ws->getItemName()) 
				activeLine.push_back(ws);			
		};

		while (!ifs.eof()) {
			std::getline(ifs, record);
			
			stationName = ut.extractToken(record, indexPos, isMore);
			for_each(startStaions, endStations, fn);
						
			if (isMore) {
				stationName = ut.extractToken(record, indexPos, isMore);
				for_each(startStaions, endStations, fn);
			}
			else 
				activeLine.push_back(nullptr);
			
			indexPos = 0;
		}
		size_t activeSize = activeLine.size();
		size_t activeLineIndex = 0;
		
		while (activeLineIndex < activeSize) {
			if (activeLineIndex % 2 == 0)
			{
				if (activeLine[activeLineIndex + 1] != nullptr)
					activeLine[activeLineIndex]->setNextStation(activeLine[activeLineIndex + 1]);
				else
					activeLine[activeLineIndex]->setNextStation(nullptr);
			}
			activeLineIndex += 2;
		}
		
		m_cntCustomerOrder = pending.size();
		isSorted = false;
		m_firstStation = nullptr;
	}
	void LineManager::linkStations() {
		bool isfound = false;
		vector<size_t> index;
		index.reserve(activeLine.size());		
		for (size_t i = 0; i < activeLine.size(); ) {			
			for (size_t j = 1; j < activeLine.size(); ) {
				if (activeLine[j] != nullptr && activeLine[i]->getItemName() == activeLine[j]->getItemName()) 
					isfound = true;					
				j += 2;
			}
			if (!isfound) {
				index.push_back(i);
				index.push_back(i + 1);
			}
			isfound = false;
			i += 2;
		}		
		size_t startNum = index[1];
		while (index.size() != activeLine.size()) {
			for (size_t i = 0; i < activeLine.size(); ) {
				if (!activeLine[startNum])
					break;
				else if (activeLine[i] && (activeLine[startNum]->getItemName() == activeLine[i]->getItemName())) {
					index.push_back(i);
					index.push_back(i + 1);
					startNum = i + 1;
					break;
				}
				i += 2;
			}
			
		}
		
		std::vector<Workstation*> sortedStation;
		for (auto& e : index) 
			sortedStation.push_back(activeLine[e]);		
		sortedStation.erase(unique(sortedStation.begin(), sortedStation.end()), sortedStation.end());
		
		size_t nullprtCount = 0;
		for (auto& e : activeLine) {
			if (e == nullptr)
				nullprtCount++;
		}
		for (size_t i = 0; i < nullprtCount; i++) sortedStation.pop_back();
		activeLine = sortedStation;
		m_firstStation = activeLine[0];

		for (size_t i = 0; i < activeLine.size(); i++) {
			if(i == activeLine.size() - 1)
				activeLine[i]->setNextStation(nullptr);
			else
				activeLine[i]->setNextStation(activeLine[i + 1]);

		}

		isSorted = true;
	}

	bool LineManager::run(std::ostream& os) {
		bool isPassed = false;
		static size_t itrNum = 0;
		static size_t searchLimit = 1;
		
		if (completed.size() < pending.size())	completed.resize(pending.size());
		if (incomplete.size() < pending.size())	incomplete.resize(pending.size());
		
		auto fn = [&](size_t i) {			
			long long itrNumCount = static_cast<long long>(i);
			if ((size_t)itrNumCount >= (pending.size() - 1)) itrNumCount = static_cast<long long>(pending.size() - 1);
			else if (itrNumCount < 0) itrNumCount = 0;
			size_t size = 0;
			
			os << "Line Manager Iteration: " << i + 1 << endl;
			static long long activeIndex = 0;
			if (i > pending.size() - 1) 
				activeIndex += 1;
			
			for (long long i = itrNumCount, j = activeIndex; i >= 0 && (size_t)j < searchLimit; i--, j++) {
				if (m_firstStation && &pending[i]) {
					if (!pending[i].isItemFilled(activeLine[j]->getItemName())) {
							size = pending[i].countItemNum(activeLine[j]->getItemName());
							deque<CustomerOrder> temp;
							temp = std::move(pending);
							pending.push_front(std::move(temp[i]));
							for (size_t k = 0; k < size; k++)
								activeLine[j]->fill(os);
							temp[i] = std::move(pending[0]);
							pending = std::move(temp);			
					}				
				}
				else
					isPassed = true;
				if(activeLine.size() > searchLimit)
					searchLimit++;
			}
		};
		
		fn(itrNum);
		if (itrNum++ > pending.size()) {
			bool isFilled = false;
			for (auto& e : pending) {
				isFilled = e.isFilled();
				if (!isFilled) {
					isFilled = false;
					break;
				}
				else
					e.isFilled();
			}

			if (isFilled) 
				isPassed = activeLine[activeLine.size() - 1]->attemptToMoveOrder();
			
		}
		

		/*if (!m_firstStation) {
			bool pass = false;
			for(auto& e : pending)
				pass = e.isFilled();
						
			for (size_t j = 0; j < activeLine.size() && activeLine[j]; j++) {
				if (activeLine[j]->getNextStation() != nullptr)
					activeLine[j]->setNextStation(m_firstStation);
			}
			if (pass) {
				for (size_t i = 0; i < activeLine.size() && activeLine[i]; i++) {
					isPassed = activeLine[i]->attemptToMoveOrder();
					if(isPassed) 
						break;
					
				}
			}
		}*/
		
		
		
		return isPassed;
	}
	void LineManager::display(std::ostream& os) const {
		if (!isSorted) {
			for (size_t i = 0; i < activeLine.size();) {
				activeLine[i]->display(os);
				i += 2;
			}
		}
		else {
			for (size_t i = 0; i < activeLine.size(); i++) 
				activeLine[i]->display(os);			
		}
	}
}