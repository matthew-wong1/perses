// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

class i2c_agent_cfg extends dv_base_agent_cfg;

// interface handle used by driver, monitor & the sequencer, via cfg handle
  virtual i2c_if vif;

  `uvm_object_utils_begin(i2c_agent_cfg)
  `uvm_object_utils_end

  `uvm_object_new

endclass
