#!/usr/bin/env python

copyright = '/*****************************************************************************\n'
copyright += '*\n'
copyright += '* Copyright (c) 2000 - 2019, Lawrence Livermore National Security, LLC\n'
copyright += '* Produced at the Lawrence Livermore National Laboratory\n'
copyright += '* LLNL-CODE-442911\n'
copyright += '* All rights reserved.\n'
copyright += '*\n'
copyright += '* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The\n'
copyright += '* full copyright notice is contained in the file COPYRIGHT located at the root\n'
copyright += '* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.\n'
copyright += '*\n'
copyright += '* Redistribution  and  use  in  source  and  binary  forms,  with  or  without\n'
copyright += '* modification, are permitted provided that the following conditions are met:\n'
copyright += '*\n'
copyright += '*  - Redistributions of  source code must  retain the above  copyright notice,\n'
copyright += '*    this list of conditions and the disclaimer below.\n'
copyright += '*  - Redistributions in binary form must reproduce the above copyright notice,\n'
copyright += '*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the\n'
copyright += '*    documentation and/or other materials provided with the distribution.\n'
copyright += '*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may\n'
copyright += '*    be used to endorse or promote products derived from this software without\n'
copyright += '*    specific prior written permission.\n'
copyright += '*\n'
copyright += '* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"\n'
copyright += '* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE\n'
copyright += '* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE\n'
copyright += '* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,\n'
copyright += '* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY\n'
copyright += '* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL\n'
copyright += '* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR\n'
copyright += '* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER\n'
copyright += '* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT\n'
copyright += '* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY\n'
copyright += '* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH\n'
copyright += '* DAMAGE.\n'
copyright += '*\n'
copyright += '*****************************************************************************/\n'
copyright += '\n'



# --------------- #
# --- Classes --- #
# --------------- #

class HFunction(object):
    def __init__(self, _name):
        if _name[-1] == '\n':
            self.name = _name[0:-1]
        else:
            self.name = _name
        self.pre_text = 'extern const char *visit_'
        self.post_text = '_doc;\n'
        
    def __str__(self):
        return self.pre_text + self.name + self.post_text


class CFunction(object):
    def __init__(self, _name):
        if _name[-1] == '\n':
            self.name = _name[0:-1]
        else:
            self.name = _name
        self.pre_text = 'const char *visit_'
        self.post_text = '_doc = \n'
    
    def __str__(self):
        output  = self.pre_text + self.name + self.post_text
        output += '"' + self.name + r'\n' + '"\n'
        output += '"' + r'\n' + '"\n'
        output += '"' + r'\n' + '"\n'
        return output


class Container(object):
    """
        A container to hold and format documentation.
    """
    def __init__(self):
        self.text = []
        self.last = False
    
    def extend(self, extension):
        self.text.append(extension)
    
    def set_last(self, is_last):
        self.last = is_last
    
    def __str__(self):
        """
            Overridden str method. When str() is called on
            the Container, it will be converted to a string
            formatted for MethodDoc.C

            returns:
                A formatted string. 
        """
        if self.last:
            self.text = self.text[0:-1]
        output  = '"' + self.title + r'\n' + '"\n'
        output += '"' + r'\n' + '"\n'
        for line in self.text:
            output += '"' + line + r'\n' + '"\n'
        if self.last:
            output += ';\n'
        else:
            output += '"' + r'\n' + '"\n'
            output += '"' + r'\n' + '"\n'
        return output


class SynopsisContainer(Container):
    def __init__(self):
        self.title = 'Synopsis:'
        Container.__init__(self)


class ArgumentsContainer(Container):
    """
        A container to hold and format a function synopsis. 
    """ 
    def __init__(self, arg_name):
        self.title = 'Arguments:'
        Container.__init__(self)
        self.text.append(split_colon_add_spaces(arg_name))

    def extend(self, extension):
        self.text.append(split_colon_add_spaces(extension))


class ReturnsContainer(Container):
    def __init__(self):
        self.title = 'Returns:'
        Container.__init__(self)


class DescriptionContainer(Container):
    def __init__(self):
        self.title = 'Description:'
        Container.__init__(self)


class ExampleContainer(Container): 
    def __init__(self):
        self.title = 'Example:'
        Container.__init__(self)



# ----------------- #
# --- Functions --- #
# ----------------- #
    
def insert_into_string(text, position, char):
    return text[:position] + char + text[position:]

def insert_backslash(text):
    # Generate a list of indices where " appears in the text
    indices = [i for i, ltr in enumerate(text) if ltr == '"']
    # Insert backslashes at the locations. Because this modifies the string, we
    # need to do this in reverse order
    for ndx in reversed(indices):
        text = insert_into_string(text, ndx, '\\')
    return text

def split_colon_add_spaces(line):
    if line.find(':') > -1:
        output = line.split()[0]
    else:
        output = '    ' + line
    return output


def write_state(writer, state_dict):
    if state_dict['synopsis']:
        writer.write(str(state_dict['synopsis']))
    if state_dict['arguments']:
        writer.write(str(state_dict['arguments']))
    if state_dict['returns']:
        writer.write(str(state_dict['returns']))
    if state_dict['description']:
        writer.write(str(state_dict['description']))
    if state_dict['example']:
        writer.write(str(state_dict['example']))
    
    
    
# ------------ #
# --- Main --- #
# ------------ #

if __name__ == '__main__':

    func_file   = open('cli_manual/functions.rst', 'r')
    h_output    = open('../visitpy/common/MethodDoc.h','w')
    c_output    = open('../visitpy/common/MethodDoc.C','w')
    
    h_output.write(copyright)
    c_output.write(copyright)
    
    block_dict = {'synopsis': None, 'arguments': None, 'returns': None, 'description': None, 'example': None}
    cur_block = None
    first_func = True
    
    func_file_lines = func_file.readlines()
    for i in range(0, len(func_file_lines)):
        line = insert_backslash(func_file_lines[i])
        # print line[0:-1]
        
        if line[0] in ['\n', '|', ':', '='] or line == 'Functions\n':
            continue
            
        if line[0] == '-': # The previous line was a function name
            # Output the last state of the block_dict
            if not first_func:
                block_dict[cur_block].set_last(True)
                write_state(c_output, block_dict)
        
            first_func = False
            # Setup the next function
            cur_block = 'Function:'
            block_dict = {'synopsis': None, 'arguments': None, 'returns': None, 'description': None, 'example': None}
            h_output.write(str(HFunction(func_file_lines[i-1])))
            c_output.write(str(CFunction(func_file_lines[i-1])))
            
        elif line[0:13] == '**Synopsis:**':
            cur_block = 'synopsis'
            block_dict['synopsis'] = SynopsisContainer()
            
        elif cur_block != 'arguments' and line[0:6] != 'return' and line.find(' : ') > -1:
            cur_block = 'arguments'
            block_dict['arguments'] = ArgumentsContainer(line.strip())
            
        elif line[0:6] == 'return':
            cur_block = 'returns'
            block_dict['returns'] = ReturnsContainer()
            
        elif line[0:16] == '**Description:**':
            cur_block = 'description'
            block_dict['description'] = DescriptionContainer()
            
        elif line[0:12] == '**Example:**':
            cur_block = 'example'
            block_dict['example'] = ExampleContainer()
            
        elif cur_block is not None:
            block_dict[cur_block].extend(line.strip())
   
    func_file.close()
    h_output.close()
    c_output.close()
    
    
    
    
