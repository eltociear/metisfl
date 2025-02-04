
#ifndef METISFL_METISFL_CONTROLLER_SCHEDULING_SCHEDULER_H_
#define METISFL_METISFL_CONTROLLER_SCHEDULING_SCHEDULER_H_

#include <vector>
#include <string>

#include "metisfl/proto/metis.pb.h"

namespace metisfl::controller {

// A scheduler implements the synchronization and coordination policy of learners.
class Scheduler {
 public:
  virtual ~Scheduler() = default;

  // Returns the ids of all learners that need to be scheduled, given that
  // learner `learner_id` has just completed its task.
  virtual std::vector<std::string> ScheduleNext(
      const std::string &learner_id,
      const CompletedLearningTask &task,
      const std::vector<LearnerDescriptor> &active_learners) = 0;

  virtual std::string name() = 0;
};

} // namespace metisfl::controller

#endif //METISFL_METISFL_CONTROLLER_SCHEDULING_SCHEDULER_H_
